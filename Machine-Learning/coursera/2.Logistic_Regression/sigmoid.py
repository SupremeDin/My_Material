#定义激活函数sigmoid()
import numpy as np

def sigmoid(z):
    return 1/(1 + np.exp(-z))