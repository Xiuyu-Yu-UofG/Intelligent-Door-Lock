#include "welcome.h"
#include "ui_welcome.h"
#include <opencv2/opencv.hpp>
#include<wiringPi.h>

#define LOCK_PIN 13
#define ALERT_PIN 19
Welcome::Welcome(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Welcome)
{
	ui->setupUi(this);
	wiringPiSetupGpio();
	pinMode(LOCK_PIN, OUTPUT);
	pinMode(ALERT_PIN, OUTPUT);
	ui->tabWidget->setTabEnabled(1, false);
	ui->tabWidget->setTabEnabled(2, false);
	ui->label->setPixmap(QPixmap("lock.png"));
	ui->label_save->setPixmap(QPixmap("lock.png"));
	ui->label_delete->setPixmap(QPixmap("lock.png"));
	timer1 = new QTimer(this);
	timer2 = new QTimer(this);
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(start_unlock()));
	connect(ui->save_btn, SIGNAL(clicked()), this, SLOT(start_new()));
	connect(ui->delete_btn, SIGNAL(clicked()), this, SLOT(start_delete()));
	connect(ui->lock_btn, SIGNAL(clicked()), this, SLOT(lock_now()));
	connect(timer1, SIGNAL(timeout()), this, SLOT(check_camera_thread()));
	connect(timer2, SIGNAL(timeout()), this, SLOT(check_camera_thread_save()));
	connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(check_function(int)));
	connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(displaySavedImg(QListWidgetItem*)));
}

Welcome::~Welcome()
{
	delete ui;
}

void Welcome::displaySavedImg(QListWidgetItem* item)
{
	ui->label_delete->setPixmap(QPixmap("/home/pi/LiveFaceReco_RaspberryPi/img/" + item->data(123).toString()).scaled(640, 480));
}

void Welcome::check_function(int func_index)
{
	//std::cout<<func_index<<std::endl;
	if (func_index == 1)
	{
		ui->lineEdit->setText("new_" + QString::number(QDateTime::currentMSecsSinceEpoch()));
	}
	else if (func_index == 2)
	{
		updateSavedImgs();
	}
}

void Welcome::lock_now()
{
	ui->tabWidget->setTabEnabled(1, false);
	ui->tabWidget->setTabEnabled(2, false);
	lock_ret = 0;
	std::cout << "locked" << std::endl;
	digitalWrite(LOCK_PIN, LOW);
	digitalWrite(ALERT_PIN, LOW);
}

void Welcome::updateSavedImgs()
{
	QDir dir("/home/pi/LiveFaceReco_RaspberryPi/img/");
	ui->listWidget->clear();
	foreach(const QString & file_name, dir.entryList(QDir::Files))
	{
		if (file_name != "00000_0.jpg")
		{
			QListWidgetItem* list_item = new QListWidgetItem;
			list_item->setData(123, file_name);
			//list_item->setText(file_name+"    Date:"+QFileInfo("/home/pi/LiveFaceReco_RaspberryPi/img/"+file_name).lastModified().toString("yyyy-MM-dd hh:mm:ss:"));
			list_item->setText(file_name);
			list_item->setIcon(QIcon("res/icon.png"));
			ui->listWidget->addItem(list_item);
		}
	}
}

void Welcome::check_camera_thread()
{
	if (lock_ret == UNLOCKED)
	{
		cameraThread.join();
		ui->pushButton->setDisabled(false);
		timer1->stop();
		lock_ret = 0;
		ui->tabWidget->setTabEnabled(1, true);
		ui->tabWidget->setTabEnabled(2, true);
		std::cout << "unlocked" << std::endl;
		digitalWrite(LOCK_PIN, HIGH);
		digitalWrite(ALERT_PIN, LOW);
	}
	else if (lock_ret == ALERT)
	{
		std::cout << "alert" << std::endl;
		cameraThread.join();
		ui->pushButton->setDisabled(false);
		timer1->stop();
		lock_ret = 0;
		ui->tabWidget->setTabEnabled(1, false);
		ui->tabWidget->setTabEnabled(2, false);
		digitalWrite(LOCK_PIN, LOW);
		digitalWrite(ALERT_PIN, HIGH);
	}
}

void Welcome::check_camera_thread_save()
{
	if (save_ret != 0)
	{
		cameraThread_save.join();
		ui->save_btn->setDisabled(false);
		timer2->stop();
		save_ret = 0;
	}
}

void Welcome::start_unlock()
{
	cameraThread = std::thread(&MTCNNDetection_qt, ui->label, std::ref(lock_ret));
	ui->pushButton->setDisabled(true);
	timer1->start(500);
}

void Welcome::start_new()
{
	cameraThread_save = std::thread(&MTCNNDetection_qt_save, ui->label_save, ui->lineEdit->text(), std::ref(save_ret));
	ui->save_btn->setDisabled(true);
	timer2->start(500);
}

void Welcome::start_delete()
{
	QString del_cmd = "rm /home/pi/LiveFaceReco_RaspberryPi/img/" + ui->listWidget->currentItem()->data(123).toString();
	system(del_cmd.toStdString().c_str());
	updateSavedImgs();
	ui->label_delete->setPixmap(QPixmap("lock.png"));
}

void Welcome::closeEvent(QCloseEvent* e)
{
	e->accept();
	//    qApp->quit();
}