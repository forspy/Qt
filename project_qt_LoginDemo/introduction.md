# 登陆界面LoginDemo #
**采用的基类是QDialog**

**.qss样式表文件：样式表就是各种控件的衣服**

qss样式路径E:\tanzhou\TZKT\resources\ui\qss\login_widget_ui

QWidget#wdLoginFrom{
border-image: url(./resources/ui/skin/12anniversary/dlbg.png);
}

看到这个url里面的资源图片

![](./pic/dlbg.png)

 **加载这个图片的做法：**

在同一目录下创建image文件夹 在文件夹下继续创建png文件夹 将png图片存入  同时还可以创建一个ico文件夹用于存放图标

dlbg.png的分辨率为317X491

**添加资源文件**

**1.右键项目--add new**

**2.创建资源文件夹**

![](./pic/addSource.jpg)
![](./pic/addSource1.jpg)

**3.选择添加前缀(只保留/)**

![](./pic/addSource2.jpg)

**4.选择添加文件**

![](./pic/addSource3.jpg)

**5.qMake一下，把资源加载进来，选择border-image**

![](./pic/qss1.jpg)
![](./pic/qss2.jpg)

## 控件布局流程 ##

**1.添加两个pushbutton按钮**

关闭按钮的对象名称WClose,最小化WHide

**2.为两个按钮添加槽函数**

![](./pic/Signal_Slot.jpg)
![](./pic/Signal_Slot1.jpg)

**3.最小化函数接地**

![](./pic/signal1.jpg)

**4.给最小化和关闭添加图标**
	
以下是qss样式表

    	QPushButton#btnMin
    {
    	border:none;
    	image: url(./resources/ui/skin/LoginPic/zxh.png);
    }
    	
    
    	QPushButton#btnQuit
    {
    	border:none;
    	image: url(./resources/ui/skin/LoginPic/shut.png);
    }

**5.继续添加资源**

把图标添加进去

![](./pic/addSource4.jpg)
![](./pic/addSource5.jpg)

qmake一下

![](./pic/qss3.jpg)
	
[重要]需要修正背景窗口的样式表作用域,右键主Dialog修改样式表,这样的好处是规定了作用域是QDialog

![](./pic/qss4.jpg)

对应控件qss以后采用编码方式，可以通过添加资源加载路径，然后放在QPushButton作用域里面


![](./pic/qss5.jpg)

    	QPushButton
    {
    	border: none;
    	image: url(:/image/png/shut.png);
    }
    
    	QPushButton:hover
    {
    	background-color: #3e72cb;
    }

![](./pic/qss6.jpg)

    	QPushButton
    {
    	border: none;
    	image: url(:/image/png/zxh.png);
    }
    
    	QPushButton::hover
    {
    	background-color: #3e72cb;
    }

**6.通过Label控件添加图片**

	改变对象名字为labelLogo
	
	

**7.登陆方式框**

设立两个按钮，分别为pushButtonPhone和pushButtonAccount

    QPushButton#pushButtonPhone{
    	border: none;
    	color:white;
    }
    QPushButton#pushButtonPhone::checked{
    	color:#ffffff;
    	border-bottom:2px solid #43c052;
    }
![](./pic/phoneLogin.jpg)

    QPushButton#pushButtonAccount{
    	border: none;
    	color:white;
    }
    QPushButton#pushButtonAccount::checked{
    	color:#ffffff;
    	border-bottom:2px solid #43c052;
    }
![](./pic/AccountLogin.jpg)

**[重要]**两个pushButton进行编组

![](./pic/qss_group.jpg)

两个按钮分别勾选属性checkable、autoExclusive
首选手机登陆增加checked属性

![](./pic/checkAbstract.jpg)

这样就形成了这样的效果

![](./pic/Dialog2.jpg)

**8.分页窗口stacked widget**

![](./pic/stack_widget.jpg)

![](./pic/currentPage1.jpg)
![](./pic/pageLogin.jpg)

编辑QStackedWidget

![](./pic/QStackedWidget.jpg)
