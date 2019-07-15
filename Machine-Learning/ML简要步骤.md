ML时常用
====

###1.数据可视化 Visualizing the data
即用plt作图
###3.初始化数据 Initialize data
目的是得到`X`、`y`、`theta`，使得后面计算容易

- **对`dataframe`类型的原始data进行 **

**1.补一列 **
```
data.insert(0,'Ones',1)
```
**2.切片**
`dataframe`的切片 常用`.loc`,`.iloc`,`.ix`,前两个用的较多，最后一个`ix`已经过时，新版本不支持
```
X = data.iloc[:,:-1]
y = data.iloc[:,-1]
```
这里需要注意的是，`df.iloc[首行：末行，首列：末列]`，-1代表最后一列～

**3.`dataframe`--->`ndarray`**
3.1 目的是后面的向量化不能使用`dataframe`的数据格式，我们使用`numpy`下面最常见的`array`格式（`numpy`下面的`matrix`格式也可以）
3.2 将`dataframe`转成`ndarray`：常用 `pandas`下面的 `df.values`， `df.as_matrix()` 或者可以用`numpy`下面的 `np.array(df)`
```
X = X.values
y = y.as_matrix()
```

```
" Method .as_matrix will be removed in a future version. Use .values instead. "
```
以后就用`.values`来转换成`array`好了

此时可用 `type(X)` 查看X的数据类型 已经穿换成`<class 'numpy.ndarray'>`
并用 `X.shape` 来查看维度，X，y，theta的维度合适可以进行向量的相乘、相加
###4.学习参数 Learning θ parameters
用到前面定义好的`X`,`y`,`theta`，通过定义的各种函数来拟合**θ**

下面是所需函数：

- **sigmoid()**	
	1.用到 `np.exp()` numpy下面的指数函数
	2.画水平直线的技巧：y2 = 0.5 +x1*0   注：y2 = 0.5是不会出现水平直线的，需要加上x1×0

- **costFunction()**
搞清楚什么时候是**`array/mat对应元素相乘？`**，**`array/mat作矩阵乘积？`**

| 乘法种类 | 操作 |
| :----: | :-----: |
| 元素相乘 | numpy.multply(a,b) |
| 矩阵相乘 | numpy.dot(a,b) 、numpy.matmul(a,b) 、a @ b|

` * `: 是特别的。在`array`操作中，作为**元素相乘**；在`matrix`操作中作为**矩阵相乘**。

> 对应元素相乘时：
> 矩阵相乘时候：一般情况下，只要a，b满足行列规则，即可进行矩阵相乘。（此时仍得到矩阵array）；当`行向量自身作矩阵相乘`时，将其看做求`行向量的模`，得到一个数值（而非array）求模时，仅限于行向量，列向量并不满足。因为在numpy中，默认的向量是行向量！
 
 - **Gradient Descent梯度下降函数 & SciPy包里面的fimin_tnc或者minimize方法**
 	1.在第一章`Linear Regression`中，我们是自己定义了梯度下降函数来使得cost值降低，其函数模型为 
 
 >GradientDescent(X,y,theta,alpha,epoch)

`alpha`:learning rate
`epoch`:迭代次数
2.第二章` Logistic Regression `中，自己按照chapter 1，实现了梯度下降函数，但是效果并不理想：

|自写的梯度下降函数来优化cost|before|after[ `学习率`0.001，`epoch`1000 ]|>|使用SciPy包里面的fimin_tnc或者minimize方法来拟合|
|--|--|--||--|
|cost的变化|0.6931471805599453|0.6249857589104834|>|0.2034977015894744|
|theta的变化|[0 0 0]|[-0.06946097  0.01090733  0.00099135]|>|[-25.16131844,   0.20623159,   0.20147148]|


可见，用自己写的梯度下降函数来优化cost值的下降是有限的。（后面尝试增加epoch，或者修改Learning rate 均不能有较大的改善：算法本身不够高效）
3.放弃自己写的梯度下降，改用SciPy包里面的fimin_tnc或者minimize方法来拟合。

> result = opt.fmin_tnc(func=cost, x0=theta, fprime=Gradient, args=(X, y))
result =
(array([-25.16131867,   0.20623159,   0.20147149]), 36, 0)  //theta,epoch,error

使用包里面的函数自然简单：只需要把函数参数一一对应就OK。这里的分fprime参数是求得cost函数的梯度Gradient，并不是梯度下降函数。并且，通过表格里面的cost变化，发现的确高效！

至此，已经学习好了参数** θ**

###5.预测 Evaluating logistic regression
学习好了参数 **θ** 后，将 **θ** 带入假设函数 **h(x)** 即得到`逻辑回归的模型`（或称 `逻辑回归分类器`）。用这个模型进行预测。

- 如果没有提供测试集 testing set，可以拿training set进行对模型的验证 （但这样会有问题，预测的精度可能没那么高，因为是training set！）
- 首先，构造一个预测结果的list（名为`predictions`），其长度、类型跟正确值`y`一致。
- 然后，对`predictions`，`y`进行比较，看有多少是相同的，即查看预测结果 跟 真实值 的相同率
- 这里可以自己写函数，也可以用scikit-learn包里面的classification_report进行分析：

> from sklearn.metrics import classification_report
print(classification_report(predictions, y))

###6.画出决策边界 Decision Boundary
什么是`决策边界`？

- **h(x)=0** 这条曲线(直线)

- 所以在本例中 另 **θ0+θ1\*x+θ2\*x=0** ，很明显，这是一条直线，即**x2=f(x1)**

- 一个`ax`只能有一个 `plt.show()`,所以在`plt.show()`之前加的所有代码都会显示在ax这张图上。

逻辑回归第一部分 Done!
***

***
##逻辑回归的第二部分
- 逻辑回归 到底是线性的 还是非线性的？
答：本质上是线性回归模型，是关于系数**θ**的线性函数（无论其决策边界是线性的，还是非线性的）
###2.1 Visualizing the data

- 将数据可视化之后，发现`正类`跟`负类`两类数据之间，==没有线性的决策边界！！！==
- 直接使用`Logistic Regression`在这个数据集上并不能表现良好，因为直接使用逻辑回归，使用`Raw feature`（x0,x1,x2,......,xn）的线性组合，即最后只能找到一个 线性的决策边界。
- 下面，用`特征映射`Feature mapping来解决这个问题。

###2.2 Feature mapping

- 受启发链接：多项式特征映射 [Feature mapping](https://www.zhihu.com/question/65020904) 
- **定义** 
如果样本量多，逻辑回归问题很复杂，而原始特征只有x1,x2可以用多项式创建更多的特征x1、x2、x1x2、x1^2x2^2、... X1^n ,X2^n。因为更多的特征进行逻辑回归时，==得到的分割线可以是任意高阶函数的形状==。

- 一句话：通过Feature mapping来增加特征。（以得到更好的决策边界）
- 在第二个例子中，通过使用`特征映射`，将原先只有x1,x2两个特征向量，转化成了具有28个特征的向量（28维）
- 当只有x1,x2两个特征时，在二维图上画出的	决策边界`决策边界`是==线性的==
- 当有x1,x2,x3,......x28等这么多的特征时，在二维图上画出的`决策边界`是==非线性的==
- 特征映射允许我们构建一个`更有表现力的分类器`，但他也更容易导致==过拟合==
- ==正则化Regularition 来消除（减少）过拟合==
###2.3Regularized Cost function
###2.4Regularized gradient

以上已经将准备工作做好了！现在就需要进行学习参数！
###2.5Learning parameters
- 在Linear Regression时，由于模型简单，一般都是自己来写`梯度下降`函数，属于最简单的！在逻辑回归这里，多选用sklearn中已经做好的`最小化函数`，他将==比自己写的梯度下降函数收敛的更快==
- 所包含的包为：import scipy.optimize as opt




###重要技巧
- 在计算Regularized Cost function、Regularized gradient时候，我们的技巧是：先计算没有正则化时候的Cost function、gradient，然后再在其基础上+reg项。
- 对于Regularized Cost function：reg项是一个`数值`，因为cost本身也是一个`数值`
- 对于Regularized gradient：reg项是一个`向量`，其维度跟theta是一致的！

###逻辑回归不能形成更复杂的假设，因为让只是一个线性分类器。
- 逻辑回归：线性？对于`theta`来说，的确是线性的
- 神经网络：可以实现非常复杂的非线性模型。

































