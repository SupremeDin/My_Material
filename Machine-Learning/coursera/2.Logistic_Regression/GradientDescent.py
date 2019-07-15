#定义批量梯度下降函数

import numpy as np
from sigmoid import *
#from CostFunction import *
from cost import *

def GradientDescent(X,y,theta,alpha,epoch):
    m = len(X)
    temp = np.zeros(theta.shape)
    costHistory = np.zeros(epoch)
    for i in range(0,epoch):
        temp = theta - (alpha/m)*((sigmoid(X @ theta) - y)@X)   # 3×1 = 3*1 - 3×1 更新theta的值
        #从这里可以更好地看出梯度下降的实质：每epoch一次，参数theta-一个微分项
        theta = temp
        costHistory[i] =cost(theta, X, y)
    return theta,costHistory