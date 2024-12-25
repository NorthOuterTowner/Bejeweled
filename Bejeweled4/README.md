# Bejeweled
 宝石迷阵
## 说明
各种宝石相关的接口基本已经定义完善，如有问题，欢迎联系。
对项目架构略作简要说明：
———— Bejeweled
 |—— Header Files
 | |—— game.h 游戏对话框相关方法和变量定义
 | |—— globalvalue.h 项目全局变量的extern声明
 | |—— stonelabel.h 宝石相关方法和变量定义（继承了QLabel）
 | `—— mainwindow.h 开始游戏时的窗口
 |
 |—— Source Files
   |—— game.cpp 游戏对话框相关方法
   |—— globalvalue.cpp 项目全局变量的定义
   |—— mainwindow.cpp 开始游戏时的窗口
   |—— stonelabel.cpp 宝石相关方法
   `—— main.cpp
