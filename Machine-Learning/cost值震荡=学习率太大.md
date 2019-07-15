第一次碰到cost值震荡
====
星期一, 03. 六月 2019 07:12下午 

- 在第二章logistics regression时候，计算每次epoch时候所得到的cost值并将其可视化，查看模型的好坏，**发现震荡**！

- 受到启发的链接: [numpy出现runtime warning的解决思路](http://www.maixj.net/ict/numpy-warning-19356) 

- 从上面的链接中收到启发：cost值出现震荡，极有可能是因为 Learning rate值过大！
![ ](/home/din/Pictures/Screenshot-20190603182923-792x393.png  "cost值震荡")

- 初始选择
> Learning rate：0.01 
   epoch   : 100 	次
   
    这两个值的选择是没有依据的，造成了震荡的出现。（并且由于震荡的出现，使得numpy出现runtime warning）
    
- 人为的降低Learning Rate ----->0.001 得到cost值如下
![ ](/home/din/Pictures/Screenshot-20190603222016-790x391.png  "震荡消失")