# Intelligent-Door-Lock
This is a group assignment for the course ENG5220: Real Time Embedded Programming (2022-23)

Xiuyu Yu(2798559Y), Wenwei Zheng(2814293Z): Responsible for the design of image recognition.                                                                          Xu Feng(2781961F), Zhihong Cheng(2802378C): Responsible for GPIO, UI design.

## Introduction

This project has implemented both facial recognition and anti-spoofing on a Raspberry Pi, with its model converted to ncnn. In addition, the entire project is designed as an entry protection system, which reads facial images from the img folder and determines whether the input face is in the dataset using Arcface. The most interesting feature is its ability to estimate whether a facial image obtained from a camera is real, relying solely on the input image rather than using human or temperature sensors. As a result, it can avoid being deceived by fake faces, including printed paper photos and electronic device displays. In addition, this smart lock can enter the setting function by entering the password.

This project uses ncnn as the inference framework to deploy the model, the main models used are

- Neural Network Inference

  [ncnn](https://github.com/Tencent/ncnn)

- Detection:

  [mtcnn](https://kpzhang93.github.io/MTCNN_face_detection_alignment/index.html)

- Recognition: 

  [MobileFaceNet](https://github.com/deepinsight/insightface/issues/214)

-  Anti-Spoofing:

    [Face-Anti-Spoofing](https://github.com/minivision-ai/Silent-Face-Anti-Spoofing)

The UI is designed by QT

---

## Installation Environment Configuration
### 1.Expand the file system of Raspberry Pi
The storage space of the Raspberry Pi is limited, we need to expand the file space, first enter in the terminal:
```
$ sudo raspi-config
```
choose'Advanced Options', then click 'expand filesystem' to free up computer storage space

![expand_system](./picture/expand_system.jpg)
### 2.Add swap space SWAP to Raspberry Pi
Before starting to compile, it is recommended that you increase the swap space. This will allow you to use all four cores of the Raspberry Pi to compile OpenCV without the compilation hanging due to memory exhaustion. Type:
```
sudo nano /etc/dphys-swapfile
```
to open the file, then edit the CONF_SWAPSIZE variable to 2048 or 1024.
### 3.The tools and some image and video libraries required to install OpenCV
#### 3.1 Install the CMake developer tools
Enter the following command to install build-essential, cmake, git and pkg-config
```
sudo apt-get install build-essential cmake git pkg-config 
```
#### 3.2 Install Common Image Toolkit: Allows us to load various image file formats from disk
Enter the following command to install the jpeg format image toolkit
```
sudo apt-get install libjpeg8-dev 
```
Enter the following command to install the tif format image toolkit
```
sudo apt-get install libtiff5-dev 
```
Install png image toolkit
```
sudo apt-get install libpng12-dev
```
#### 3.3 Install common video libraries
Let us read various video file formats from disk, and use video streams directly
```
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
sudo apt-get install libxvidcore-dev libx264-dev
```
### 4.Download OpenCV-4.0.0
```
wget -O opencv-4.0.0.zip https://github.com/Itseez/opencv/archive/4.0.0.zip
```
### 5.Install and compile OpenCV
```
# change to your dir
cd /home/opencv

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DOPENCV_GENERATE_PKGCONFIG=ON -DCMAKE_INSTALL_PREFIX=/usr/local ..
sudo make
sudo make install
```

## Performance


https://user-images.githubusercontent.com/53292073/232580126-32e528dd-9edc-4c5a-87d5-7a5e811967f7.mp4

https://user-images.githubusercontent.com/53292073/232581115-4b8f5573-edaf-49e1-a63b-15600a13e8ec.mp4

Faces can be recognized correctly, and real and fake faces can be distinguished.


---

## Dependency

- OpenCV >= 4.0.0 

---

## Adjustable Parameters

1. **largest_face_only:** whether only the largest faces are detected
2. **record_face:** detects faces every two seconds in the next run and writes them to the img folder as a database
3. **distance_threshold:** prevents false detection of faces that are too far away
4. **face_thre:** Face recognition threshold
5. **true_thre:** threshold for live body detection
6. **jump:** skip a few frames of face recognition and live detection to speed up the process
7. **input_width:** set input width 
8. **input_height:** set input height 
9. **output_width:** set output width 
10. **output_height:** set input height
11. **project_path:** must be set to your own directory

------
## Object and UI
![Object](https://user-images.githubusercontent.com/53292073/232586877-f13f32ed-0ef7-4d6d-a4a2-a97fb9cff62a.png)

![UI](https://user-images.githubusercontent.com/53292073/232586916-aa48ae67-ea54-4666-9793-996e22e44cfe.png)


## Social Media
>[Our Youtube Channel! Click here to follow.](https://www.youtube.com/channel/UCksbdr3oxr3xwcaTyatUlkw)   
>[Our Twitter! Click here to follow.](https://twitter.com/5220SmartLock) 
---



