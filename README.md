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

# Social Media

---
