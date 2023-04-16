# Intelligent-Door-Lock
This is a group assignment for the course ENG5220: Real Time Embedded Programming (2022-23)

## Introduction

This project has implemented both facial recognition and anti-spoofing on a Raspberry Pi, with its model converted to ncnn. In addition, the entire project is designed as an entry protection system, which reads facial images from the img folder and determines whether the input face is in the dataset using Arcface. The most interesting feature is its ability to estimate whether a facial image obtained from a camera is real, relying solely on the input image rather than using human or temperature sensors. As a result, it can avoid being deceived by fake faces, including printed paper photos and electronic device displays.

This project uses ncnn as the inference framework to deploy the model, the main models used are

- Neural Network Inference

  [ncnn](https://github.com/Tencent/ncnn)

- Detection:

  [mtcnn](https://kpzhang93.github.io/MTCNN_face_detection_alignment/index.html)

- Recognition: 

  [MobileFaceNet](https://github.com/deepinsight/insightface/issues/214)

-  Anti-Spoofing:

    [Face-Anti-Spoofing](https://github.com/minivision-ai/Silent-Face-Anti-Spoofing)

---
## Performance



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


## Social Media

---


## Citation

> ```
> @inproceedings{deng2018arcface,
> title={ArcFace: Additive Angular Margin Loss for Deep Face Recognition},
> author={Deng, Jiankang and Guo, Jia and Niannan, Xue and Zafeiriou, Stefanos},
> booktitle={CVPR},
> year={2019}
> }
> 
> @inproceedings{deng2019retinaface,
> title={RetinaFace: Single-stage Dense Face Localisation in the Wild},
> author={Deng, Jiankang and Guo, Jia and Yuxiang, Zhou and Jinke Yu and Irene Kotsia and Zafeiriou, Stefanos},
> booktitle={arxiv},
> year={2019}
> }
> 
> @inproceedings{ncnn,
> title={ncnn https://github.com/ElegantGod/ncnn},
> author={ElegantGod},
> }
> 
> @inproceedings{Face-Recognition-Cpp,
> title={Face-Recognition-Cpp https://github.com/markson14/Face-Recognition-Cpp},
> author={markson14},
> }
> 
> @inproceedings{insightface_ncnn,
> title={insightface_ncnn https://github.com/KangKangLoveCat/insightface_ncnn},
> author={KangKangLoveCat},
> }
> 
> @inproceedings{Silent-Face-Anti-Spoofing,
> title={Silent-Face-Anti-Spoofing https://github.com/minivision-ai/Silent-Face-Anti-Spoofing},
> author={minivision-ai},
> }
> ```
>
> 
