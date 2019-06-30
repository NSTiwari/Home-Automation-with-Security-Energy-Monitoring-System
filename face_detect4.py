import cv2
import numpy as np
import serial
import time

face_cascade = cv2.CascadeClassifier('C:/Users/Mr. Nitin Tiwari/AppData/Local/Programs/Python/Python37-32/Lib/site-packages/cv2/data/haarcascade_frontalface_default.xml')
font = cv2.FONT_HERSHEY_SIMPLEX
ser = serial.Serial('COM14', 9600, timeout=0)
isopen = cv2.VideoCapture(0)
rec = cv2.face.LBPHFaceRecognizer_create()
rec.read('abcd.yml')
times = 0
count = 0
id = 0
while isopen.isOpened():
    for times in range(0, 30):
        ret, img = isopen.read()

        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)
        for (x, y, w, h) in faces:
            cv2.imshow('img', img)
            id, conf = rec.predict(gray[y:y + h, x:x + w])
            print(id)
            if id == 1 and conf>70:
                id = "Nitin {0:.2f}%".format(round(conf, 2))
                cv2.putText(img, str(id), (x, y - 40), font, 1, (255, 255, 255), 3)
                cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 2)
                roi_gray = gray[y:y + h, x:x + w]
                count = count + 0.035
                if count >= 1 and conf>80:
                    ser.write(b'v')
                    time.sleep(1)
                elif count>=1 and conf<80:
                    ser.write(b'x')
                    time.sleep(1)
            elif id == 2 and conf>70:
                id = "Mummy {0:.2f}%".format(round(conf, 2))
                cv2.putText(img, str(id), (x, y - 40), font, 1, (255, 255, 255), 3)
                cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 2)
                roi_gray = gray[y:y + h, x:x + w]
                count = count + 0.035
                if count >= 1 and conf>80:
                    ser.write(b'v')
                    time.sleep(1)
                elif count >= 1 and conf < 80:
                    ser.write(b'x')
                    time.sleep(1)

            elif (id==1 or id==2) and conf<70:
                id="Unauthenticated Person {0:.2f}%".format(round(conf, 2))
                cv2.putText(img, str(id), (x, y - 40), font, 1, (255, 255, 255), 3)
                cv2.rectangle(img, (x, y), (x + w, y + h), (0, 0, 255), 2)
                roi_gray = gray[y:y + h, x:x + w]
                count = count + 0.035
                if count >= 1 and conf<80:
                    ser.write(b'x')
                    time.sleep(1)

            cv2.imshow('img', img)
    count = 0

    if cv2.waitKey(10) & 0xFF == ord('q'):
        isopen.release()
        cv2.destroyAllWindows()
