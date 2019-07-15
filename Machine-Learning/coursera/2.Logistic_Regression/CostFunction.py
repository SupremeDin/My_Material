#定义损失函数



import numpy as np
from sigmoid import *

def costFunction(X,y,theta):
    first = -y * np.log(sigmoid(X@theta))   #第一次时候漏掉了-，符号，导致costfunction出错，直至后面在epoch的时候出现震荡
    second = (1-y) * np.log(1-sigmoid(X@theta))
    return np.mean(first - second)
#   return np.sum(first - second)/len(X)
