#返回 一个长度为len(X) 的list，类似：[1,1,0,0,0,0,1,1,0,1,0,......]
#用到python中的`链表推导式` 简化编程

from sigmoid import *
import numpy as np

def predict(final_theta,X):
    probability = sigmoid(X @ final_theta)   #这个概率是通过h(x)求出来的
    return [1 if x >= 0.5 else 0 for x in probability]   #return a list