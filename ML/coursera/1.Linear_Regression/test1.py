import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#other modules
from computeCost import *   #从modules中全部倒入
from gradientDescent import *

#================= Part 1: Ploting ================
path = 'ex1data1.txt'
data = pd.read_csv(path,header=None,names=['Population','Profit'])
data.head()
data.plot(kind='scatter',x='Population',y='Profit',figsize=(8,5))
plt.show()

#================= Part 2: Initialize X,y,theta =======
#print(type(data)) <class 'pandas.core.frame.DataFrame'>
#将data加入一列1元素，构成[X,y]的形式，其中X是m×2的矩阵，y是列向量。
data.insert(0, 'Ones', 1)   #pandas的insert(),在第0列插入，列名=‘ones’，值全等于1，若不相等可用[.....]来定义
# set X (training data) and y (target variable)
cols = data.shape[1]
#print(cols) 3列，索引值为0,1,2
X = data.iloc[:,0:cols-1]
y = data.iloc[:,cols-1:cols]
#print(X.head)
#print(y.head)

#因为上面的X，y是pandas下面的DataFrame格式，类似于excel表中的数据，有索引，不能相乘，因为不是矩阵，print一下看看
#为了向量化，所以必须将上面的数据X，y转换成矩阵（matrix或者array，两者都是numpy包里的主要对象，其元素是同一种类的）
#python的dataframe转换为多维矩阵有两种方法，一种利用as_matrix()属性，一种利用values
#print(type(X))
#print(type(y))
#print(X.values)
#print(type(X.values))
# 测试之后发现，X,y由 pandas.dataframe-->numpy.ndarray

#代价函数是应该是numpy矩阵，所以我们需要转换X和Y，然后才能使用它们。 我们还需要初始化theta。
#X = np.matrix(X.values)
X = X.values  #都是可以的
y = np.matrix(y.values)
#print(X)
#初始化theta=[0,0] ,即我们的终极目标theta1初始化为0，theta2初始化为0
theta = np.matrix([0,0])

#检查一下X y theta 的维度
#print(X.shape,y.shape,theta.shape)
#(97, 2) (97, 1) (1, 2)

#计算初始代价函数的值
computeCost(X,y,theta)
#print(computeCost(X,y,theta))
#32.072733877455676 值为当(theta0,theta1) = [0,0]时的代价函数的值

#======================= Part 3: Gradient descent==========

#初始化：学习速率α和要执行的迭代次数epoch
alpha = 0.01
epoch = 1000

#现在让我们运行梯度下降算法来将我们的参数θ适合于训练集
#final_theta是迭代了1000次后得到的最优解【*,*】
final_theta,cost = gradientDescent(X,y,theta,alpha,epoch)

#最后，我们可以使用我们拟合的参数计算训练模型的代价函数（误差)
#32.072733877455676 值为当(theta0,theta1) = [0,0]时的代价函数的值
computeCost(X,y,final_theta)
#print(final_theta)   [[-3.24140214  1.1272942 ]]
#print(computeCost(X,y,final_theta))   4.515955503078912 相较于最开始，的确降低了很多，是不是最优？

#=================== Part 4：在原始数据上 绘制线性模型以及数据===========
x = np.linspace(data.Population.min(),data.Population.max(),100)
#print(x)
f = final_theta[0,0] + final_theta[0,1] * x
#print(f)

fig,ax = plt.subplots(figsize=(20,15))
ax.plot(x,f,'r',label='Prediction')
ax.scatter(data.Population,data.Profit,label='Training Data')
ax.legend(loc=2)
ax.set_xlabel('Population')
ax.set_ylabel('Profit')
ax.set_title('Predicted Profit vs. Population Size')
plt.show()
#=================== Part 5:绘制cost下降的函数=======================
fig,ax = plt.subplots()
ax.plot(np.arange(epoch),cost,'r')
ax.set_xlabel('Iterations')
ax.set_ylabel('Cost')
ax.set_title('Error vs. Training Epoch')
plt.show()

#==================== Done ====================

path = 'ex1data2.txt'
data2 = pd.read_csv(path,header=None,names=['Size','Bedrooms','Price'])
print(data2.head())