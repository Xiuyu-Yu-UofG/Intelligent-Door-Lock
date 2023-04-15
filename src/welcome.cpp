#include "welcome.h"
#include "ui_welcome.h"
#include <opencv2/opencv.hpp>
#include<wiringPi.h>

#define LOCK_PIN 13
#define ALERT_PIN 19
Welcome::Welcome(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Welcome)
{
    ui->setupUi(this);
    wiringPiSetupGpio();
    pinMode(LOCK_PIN,OUTPUT);
    pinMode(ALERT_PIN,OUTPUT);
    ui->tabWidget->setTabEnabled(2,false);
    ui->tabWidget->setTabEnabled(3,false);
    ui->label->setPixmap(QPixmap("res/lock.png"));
    ui->label_save->setPixmap(QPixmap("res/lock.png"));
    ui->label_delete->setPixmap(QPixmap("res/lock.png"));
    timer1=new QTimer(this);
    timer2=new QTimer(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(face_unlock()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(code_unlock()));
    connect(ui->save_btn,SIGNAL(clicked()),this,SLOT(start_new()));
    connect(ui->save_code_btn,SIGNAL(clicked()),this,SLOT(change_code()));
    connect(ui->delete_btn,SIGNAL(clicked()),this,SLOT(start_delete()));
    connect(ui->lock_btn,SIGNAL(clicked()),this,SLOT(lock_now()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(check_camera_thread()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(check_camera_thread_save()));
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(check_function(int)));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem *)),this,SLOT(displaySavedImg(QListWidgetItem *)));
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::displaySavedImg(QListWidgetItem *item)
{
    ui->label_delete->setPixmap(QPixmap("/home/pi/Intelligent-Door-Lock/img/"+item->data(123).toString()).scaled(640,480));
}

void Welcome::check_function(int func_index)
{
    //std::cout<<func_index<<std::endl;
    if(func_index==2)
    {
       ui->lineEdit->setText("new_"+QString::number(QDateTime::currentMSecsSinceEpoch()));
    }
    else if(func_index==3)
    {
       updateSavedImgs();
    }
}

void Welcome::change_code()
{
   if(ui->passwd_Edit_new->text().length()<4)
   {
      return;
   }
   QFile code_file("code");
   code_file.open(QFile::WriteOnly);
   code_file.write(ui->passwd_Edit_new->text().toUtf8());
   code_file.close();
   ui->passwd_Edit_new->clear();
}

void Welcome::lock_now()
{

   ui->tabWidget->setTabEnabled(2,false);
   ui->tabWidget->setTabEnabled(3,false);
   lock_ret=0;
   std::cout<<"locked"<<std::endl;
   digitalWrite(LOCK_PIN,LOW);
   digitalWrite(ALERT_PIN,LOW);
}

void Welcome::updateSavedImgs()
{
        QDir dir("/home/pi/Intelligent-Door-Lock/img/");
        ui->listWidget->clear();
        foreach(const QString & file_name,dir.entryList(QDir::Files))
        {
            if(file_name!="00000_0.jpg")
            {
               QListWidgetItem *list_item=new QListWidgetItem;
               list_item->setData(123,file_name);
               list_item->setText(file_name);
               list_item->setIcon(QIcon("res/icon.png"));
               ui->listWidget->addItem(list_item);
            }
        }
}

void Welcome::check_camera_thread()
{
   if(lock_ret==UNLOCKED)
   {
      cameraThread.join();
      ui->pushButton->setDisabled(false);
      timer1->stop();
      lock_ret=0;
      ui->tabWidget->setTabEnabled(2,true);
      ui->tabWidget->setTabEnabled(3,true);
      std::cout<<"unlocked by face"<<std::endl;
      digitalWrite(LOCK_PIN,HIGH);
      digitalWrite(ALERT_PIN,LOW);
   }
   else if(lock_ret==ALERT)
   {
      std::cout<<"alert"<<std::endl;
      cameraThread.join();
      ui->pushButton->setDisabled(false);
      timer1->stop();
      lock_ret=0;
      ui->tabWidget->setTabEnabled(2,false);
      ui->tabWidget->setTabEnabled(3,false);
      digitalWrite(LOCK_PIN,LOW);
      digitalWrite(ALERT_PIN,HIGH);
   }
   else if(lock_ret==EXIT)
   {
      std::cout<<"normal exit"<<std::endl;
      cameraThread.join();
      ui->pushButton->setDisabled(false);
      timer1->stop();
      lock_ret=0;
   }
}

void Welcome::check_camera_thread_save()
{
   if(save_ret!=0)
   {
      cameraThread_save.join();
      ui->save_btn->setDisabled(false);
      timer2->stop();
      save_ret=0;
   }
}

void Welcome::code_unlock()
{
    QFile code_file("code");
    code_file.open(QFile::ReadOnly);
    QString code_true=QString::fromLocal8Bit(code_file.readAll()).trimmed();
    QString code_input=ui->passwd_Edit->text().trimmed();
    //std::cout<<code_true.toStdString()<<std::endl;
    //std::cout<<code_input.toStdString()<<std::endl;
    if(code_true==code_input)
    {
        ui->tabWidget->setTabEnabled(2,true);
        ui->tabWidget->setTabEnabled(3,true);
        std::cout<<"unlocked by code"<<std::endl;
        digitalWrite(ALERT_PIN,LOW);
    }
    ui->passwd_Edit->clear();
    code_file.close();
}

void Welcome::face_unlock()
{
    cameraThread=std::thread(&MTCNNDetection_qt,ui->label,std::ref(lock_ret));
    ui->pushButton->setDisabled(true);
    timer1->start(500);
}

void Welcome::start_new()
{
     cameraThread_save=std::thread(&MTCNNDetection_qt_save,ui->label_save,ui->lineEdit->text(),std::ref(save_ret));
     ui->save_btn->setDisabled(true);
     timer2->start(500);
}

void Welcome::start_delete()
{
    QString del_cmd="rm /home/pi/Intelligent-Door-Lock/img/"+ui->listWidget->currentItem()->data(123).toString();
    system(del_cmd.toStdString().c_str());
    updateSavedImgs();
    ui->label_delete->setPixmap(QPixmap("res/lock.png"));
}

void Welcome::closeEvent(QCloseEvent *e)
{
    e->accept();
//    qApp->quit();
}
