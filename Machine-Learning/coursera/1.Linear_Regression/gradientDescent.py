# batch gradient descent
# 批量梯度下降算法：每迭代一次，即同步更新所有的theta。

import numpy as np
from computeCost import *

def gradientDescent(X,y,theta,alpha,epoch):

    temp = np.matrix(np.zeros(theta.shape)) #temp为（1,2）的矩阵，为了同步更新
    cost = np.zeros(epoch)  #存放每次迭代完成后计算出的cost，迭代epoch次，存放epoch个值
    m = X.shape[0]
    for i in range(epoch):
        temp = theta - (alpha / m) * (X * theta.T - y).T * X
        theta = temp
        cost[i] = computeCost(X,y,theta)

    return theta,cost


