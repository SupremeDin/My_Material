#cost function:J(theta) = ...
#hypothesis :h(x) = theta.T * X （X = [1,x],n+1维的列向量）

import numpy as np

def computeCost(X,y,theta):
    inner = np.power((X * theta.T -y),2)
    #print('inner.shape = (%s,%s)' % (inner.shape[0],inner.shape[1])) #这里解释了X * theta.T
    return np.sum(inner)/(2 * len(y))          # sum/2m;  m == len(y)或者len(X),X是矩阵，len(X)返回行数。


  #数学上的累加的概念，放在matrix里面其实就是矩阵元素的加和。