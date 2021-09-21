import numpy as np
import cv2
from matplotlib import pyplot as plt
from matplotlib import image as image
import matplotlib
import easygui

## Histogram for color image, doing it for Y value in YUV
I = cv2.imread('shark2.jpeg')
# Y = cv2.cvtColor(I, cv2.COLOR_BGR2YUV)
# R1 = cv2.cvtColor(I, cv2.COLOR_BGR2RGB)
# Values = Y[:,:,0].ravel()
# Y[:,:,0] = cv2.equalizeHist(Y[:,:,0])
# Values2 = Y[:,:,0].ravel()
# img = cv2.cvtColor(Y, cv2.COLOR_YUV2BGR)
# R = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
# dst = cv.fastNlMeansDenoisingColored(img,None,10,10,7,21)
# cv2.imshow("shark", dst)
# key = cv2.waitKey()
# plt.figure(1)
# plt.subplot(221)
# plt.imshow(R1)
# plt.subplot(222)
# plt.hist(Values,bins=256,range=[0,256]);
# plt.subplot(223)
# plt.imshow(R)
# plt.subplot(224)
# plt.hist(Values2,bins=256,range=[0,256]);
# plt.show()

Y = cv2.cvtColor(I, cv2.COLOR_BGR2YUV)
R1 = cv2.cvtColor(I, cv2.COLOR_BGR2RGB)
#G = cv2.cvtColor(I, cv2.COLOR_BGR2GRAY)
Values = Y[:,:,0].ravel()
Y[:,:,0] = cv2.equalizeHist(Y[:,:,0])
Values2 = Y[:,:,0].ravel()
img = cv2.cvtColor(Y, cv2.COLOR_YUV2BGR)
#R = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
#k = np.array(([[1,4,1],[4,7,4],[1,4,1]]),dtype=float)
#blur = cv2.GaussianBlur(img,(3,3),0)
k1 = np.array([[-1,-1,-1],[-1,9,-1],[-1,-1,-1]],dtype=float)
#F = cv2.filter2D(img,ddepth=-1,kernel=k/27)
F2 = cv2.filter2D(img,ddepth=-1,kernel=k1)
#F3 = cv2.filter2D(F,ddepth=-1,kernel=k1)
S = cv2.subtract(I,F2)
cv2.imshow("dumb shark", I)
cv2.imshow("dumb shark", Y)
#cv2.imshow("Avg shark", F)
#cv2.imshow("Gaussian shark", blur)
cv2.imshow("sharp shark Gaussian", F2)
#cv2.imshow("sharp shark Avg", F3)
cv2.imshow("sub shark", S)

key = cv2.waitKey()