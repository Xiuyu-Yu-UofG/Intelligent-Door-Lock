#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QCloseEvent>
#include <opencv2/opencv.hpp>
#include "livefacereco.hpp"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include <QTimer>
#include <QDateTime>
#include <QDir>
#include <QListWidgetItem>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Welcome; }
QT_END_NAMESPACE

class Welcome : public QWidget
{
    Q_OBJECT

public:
    Welcome(QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void face_unlock();
    void code_unlock();
    void start_new();
    void start_delete();
    void check_camera_thread();
    void check_camera_thread_save();
    void check_function(int func_index);
    void displaySavedImg(QListWidgetItem *item);
    void lock_now();
    void change_code();
    
private:
    void closeEvent(QCloseEvent *e);
    void updateSavedImgs();
    std::thread cameraThread;
    std::thread cameraThread_save;
    bool show_img;
    QTimer *timer1;
    QTimer *timer2;
    int lock_ret=0;
    int save_ret=0;
    Ui::Welcome *ui;

};
#endif // WELCOME_H
