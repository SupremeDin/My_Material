#在这里只计算梯度，并没有计算梯度下降。
#计算出来的梯度是放进SciPy下的比较高级的优化算法中

import numpy as np
from sigmoid import *

def Gradient(theta,X,y):
    return (1/len(X)*(sigmoid(X@theta)-y)@X)