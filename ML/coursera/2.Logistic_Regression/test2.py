import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sigmoid import *
from CostFunction import *
from cost import *
from GradientDescent import *
from Gradient import *
from predict import *
import scipy.optimize as opt
from sklearn.metrics import classification_report


#*************1.Visualizing the data **********
data = pd.read_csv('ex2data1.txt',names=['exam1','exam2','admitted'])
data.head()
#print(data.head())
#print(data.describe())

#将原始数据data分成1/0两组  【positive，negative跟data的数据类型一直：dataframe】
positive = data[data.admitted.isin([1])]  #1  把所有的1过滤出来
#print(type(positive))
#print(type(data))
#print(positive)
negative = data[data.admitted.isin([0])]   #0  把所有的0过滤出来
#print(negative)

#将positive、negative两类画在 散点图scatter上面
fig,ax = plt.subplots(figsize=(8,5))
ax.scatter(positive['exam1'],positive['exam2'],label='Admitted')     #默认是蓝点，故不需要设置颜色，形状
ax.scatter(negative['exam1'],negative['exam2'],s=50,c='r',marker='x',label='Not Admitted')

#图例legend如何画在图外的问题,
box = ax.get_position()      #获取ax的位置，box的类型是一个四维的向量
#print(type(box))
ax.set_position([box.x0,box.y0,box.width,box.height*0.1])  #设置轴ax的位置,只将高度进行缩放
#box1 = ax.get_position()
#print(box)
#print(box1)
#ax.legend(loc='center left', bbox_to_anchor=(0.2, 1.12),ncol=3)
ax.legend(loc='lower left')   #这里本来是想将图例legend放在ax的外面，但是始终不能出现想要的效果，故将其放在（默认）放在图上

# 设置横纵坐标名
ax.set_xlabel('Exam 1 Score')
ax.set_ylabel('Exam 2 Score')
#plt.show()
#*******************2.Sigmoid function ****************
# 激活函数sigmoid()定义放在sigmoid.py里面
#下面测试一下sigmoid()函数

x1 = np.arange(-10,10,0.1)
y2 = 0.5 +x1*0   #matplotlib画水平直线的技巧，y2 = 0.5是不会出现水平直线的，需要加上x1×0
y3 = 0 + x1*0
y4 = 1 + x1*0
plt.plot(x1,sigmoid(x1),c='r')
plt.plot(x1,y2,c='b')
plt.plot(x1,y3,c='b')
plt.plot(x1,y4,c='b')
#在matplotlib中画水平、竖直线可以使用：
#vlines(x, ymin, ymax)
#hlines(y, xmin, xmax)
plt.vlines(0,0,1)
#plt.show()

#****************** 3.initial the data ***********

#print(data)  #发现data是pandas的dataframe格式，需要将其分成X，y，并将其转换成matrix格式 用于后面的向量化
#add a ones column:this will make matrix multiplication more easier
#print(data.columns)
if 'Ones' not in data.columns:
    data.insert(0,'Ones',1)
#print(data)

# set X (training data) and y (target variable)
#俗称 dataframe的切片 常用.loc,.iloc,.ix,前两个用的较多，最后一个ix已经过时，新版本不支持
X = data.iloc[:,:-1].values
y = data.iloc[:,-1].values
#print(X)
#print(y)
#将dataframe转成ndarray常用 pandas下面的 df.values df.as_matrix() 或者可以用numpy下面的 np.array(df)

#构造 theta ，元素的个数为多少：特征的数量+1 即X的列的个数
#获取向量的维度 np.shape shape[0],shape[1] 分别为查看 （行×列）（行）（列）
#print(X.shape)
#print(y.shape)
theta = np.zeros(X.shape[1])
#print(theta.shape)

#查看矩阵的维度，保证相乘、相加时候没有问题
print(X.shape)
print(y.shape)
print(theta.shape)
#print(type(X))
#print(type(y))
#print(type(theta))
#<class 'numpy.ndarray'>而不是numpy.matrix 所以相应的乘法规则就要按照ndarray来进行


print('the original cost:')
#print(costFunction(X,y,theta))  #这是损失函数的初始值，后面就要设计梯度下降算法来使得costfunction的值减小，并最终得到最优吃的参数theta、
print(cost(theta, X, y))
print('*')


#******************** 4. Batch Gradient Descent **************
#例题中直接使用了SciPy中的一个优化函数，没有自己写 批量梯度函数 这里我们试着自己实现

#定义学习率alpha，迭代次数epoch
#alpha = 0.001
#epoch = 1000

#定义一个长度为1000的数组来记录每次迭代完成后的 CostFunction函数的值


#print('before :theta =' )
#print(theta)
#theta,costHistory = GradientDescent(X,y,theta,alpha,epoch)
#print(GradientDescent(X,y,theta,alpha,epoch))
#print('after :theta =' )
#print(theta)
#print('costHistory')
#print(costHistory[999])

#尽管所得的costHistory矩阵有点问题，现将其可视化，看看效果  震荡的问题 可能是学习率太大了！！！适当减小学习率
#fix,ax = plt.subplots(figsize = (8,4))
#ax.plot(np.arange(epoch),costHistory,'r')
#plt.show()
#通过可视化 我们发现所获得的Cost竟然是震荡的？？？？ 震荡说明（可能）学习率有问题

#
Gradient(theta, X, y)
#print(Gradient(theta, X, y))

#Learning θ parameters
#使用scipy下面的optimize空间下的fimin_tnc或者minimize方法来拟合

result = opt.fmin_tnc(func=cost,x0=theta,fprime=Gradient,args=(X,y))
print(result)
#print(type(result))    (array([-25.16131844,   0.20623159,   0.20147148]), 36, 0)
#<class 'tuple'> 元组：简单理解为`簇`，即好多不同的数据类型放在一起 result就把 array 整数放在一起

#5. 预测 看看我们的模型怎么样

final_theta = result[0]     #将final_theta从result中分离出来：元组的查询
#print(final_theta)
predictions = predict(final_theta,X)   #predictions是一个充满1,0的list
correct = [1 if a == b else 0 for (a,b) in zip(predictions,y)]  #使用`链表推倒式`来定义
accuracy = np.mean(correct)
print('accuracy=')
print(accuracy)

print(classification_report(y,predictions))  # 在scikit-learn包中，这个包基于numpy，scipy，matplotlib


#6.画出决策边界 Decision boundary
#就是在原先的散点图ax上面 画一条直线
x5 = np.arange(0,130,0.1)
y5 = -(final_theta[0] +final_theta[1]*x5)/final_theta[2]
ax.plot(x5,y5)
ax.set_title('Decision bounary')
plt.show()




