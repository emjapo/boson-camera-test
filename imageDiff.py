import cv2
import numpy as np
import os
import sys

# from scipy.misc import imread
from scipy.linalg import norm
from scipy import sum, average


def compare_images(img1, img2):
    # calculate the difference and its norms
    diff = img1 - img2  # elementwise for scipy arrays
    m_norm = np.sum(abs(diff))  # Manhattan norm
    z_norm = norm(diff.ravel(), 0)  # Zero norm
    return (m_norm, z_norm)




print("Use this to compare images. Compare the raw16 images (the gray ones). You can try the acg images, but I have not tested to see if that will work.")
print()
print("All zeros mean the image is the same, so the closer to zero, the more similar the images")
print()
img1Path = os.path.normpath(input("Enter path of first image: "))
img2Path = os.path.normpath(input("Enter path of second image: "))

img1 = cv2.imread(img1Path, 0)
img2 = cv2.imread(img2Path, 0)

if img1 is None or img2 is None:
    sys.exit("Path not found. Try using an absolute path or check your spelling.")

img1 = img1.astype(float)
img2 = img2.astype(float)

#--- take the absolute difference of the images ---
res = cv2.absdiff(img1, img2)

#--- convert the result to integer type ---
res = res.astype(np.uint8)

#--- find percentage difference based on number of pixels that are not zero ---
percentage = (np.count_nonzero(res) * 100)/ res.size

print()
print("percentage difference based on number of pixels that are not zero:", "{0:.3f}%".format(percentage))

print()

n_m, n_0 = compare_images(img1, img2)
manNorm = n_m/img1.size
print("Manhattan norm: {0} / per pixel: {1:.3f}".format(n_m, manNorm))
print()
zeroNorm = n_0*1.0/img1.size
print("Zero norm: {0} / per pixel: {1:.3f}".format(n_0, zeroNorm))


