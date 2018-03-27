## 一、系统总体设计<br>
### 1、系统通用功能描述<br>
#### 顾客<br>
登录功能：负责核对ID及密码。<br>
查询商品信息功能：查询商品号、商品所属超市、商品售价、商品销量、商品库存、折扣率、折后价格、折扣开始及结束时间。<br>
用户购买功能：输入用户ID和密码登录系统后，即可实现购物、查询订单等操作。<br>
商品筛选功能：包括根据商品号号查询商品；根据价格查询商品；根据折扣率查询商品；根据超市名称查询商品。<br>
个人信息管理功能：对用户个人信息中的邮箱、电话、密码、地址进行修改。<br>
取消订单功能：在未付款前取消自己的订单。<br>
查询购买记录功能：查询购物后的订单，查看用户曾经的购物记录。<br>
#### 管理员<br>
登录功能：负责核对ID及密码。<br>
查询用户订单信息情况功能：查询管理员所在超市所有的订单信息。<br>
查询本超市内所有货物功能：查询本公司所有正在售卖的商品信息。<br>
添加新商品功能：添加新的商品，在商品发布之前可以进行修改。<br>
修改商品功能：在发布添加的新商品之前，管理员可以进行修改，或者取消添加。<br>
个人管理信息功能：允许管理员修改个人信息中的密码和邮箱。<br>
<br>
### 2.接口定义规范 <br>
本程序所有接口基本按照函数所实现的功能对应的英文或着英文简写命名，部分可能在歧义。
以下为所有接口定义、命名和实现的功能。<br>
void userLog();//顾客登陆 <br>
void addUser(LinkListC L);//顾客注册 <br>
LinkListC createUserLink();//创建顾客链表，从文件中读取元素。 <br>
void outUserLink(LinkListC L);//录入顾客信息 <br>
void logCheck(LinkListC L);//登录检测 <br>
void userSystem(LinkListC L);//顾客系统 <br>
void managePerInfo(LinkListC L);// 管理员信息 <br>
void changeTel(LinkListC L);//更改电话号码 <br>
void changePassword(LinkListC L);//更改密码 <br>
void changeEMail(LinkListC L);//更改邮箱 <br>
void changeAddress(LinkListC L);//更改地址 <br>
void searchCommodity(LinkListC);//查询商品 <br>
void byCommodityName(LinkListCommodity);//根据商品名称 <br>
void byMarketName(LinkListCommodity);//根据商店名称 <br>
void byDiscount(LinkListCommodity); //根据折扣价格 <br>
void afterSearch(LinkListCommodity,LinkListC);//顾客购买模块 <br>
void sortBySaleAmount(LinkListCommodity);//根据销量 <br>
void sortBySalePrice(LinkListCommodity);//根据售价 <br>
void recommendation(LinkListCommodity);//系统推荐 <br>
void chooseCommodity(LinkListCommodity, LinkListC);//选择商品 <br>
void afterChoose(LinkListOrder,LinkListC,LinkListCommodity);//顾客购买 <br>
int payOrder(LinkListC, LinkListOrder);//订单支付 <br>
void userOldOrder(LinkListC);//顾客原有订单 <br>
void outUserNewOrder(LinkListOrder);//录入新订单 <br>
LinkListOrder creatOrderList();//创建订单链表 <br>
LinkListCommodity creatCommodityLink();//创建商品链表<br>
char time();//获取当前时间 <br>
void managerLog();//管理员登录 <br>
LinkListM createManagerLink();//创建管理员链表，从文件中读取元素。 <br>
void addManager(LinkListM L);//管理员注册 <br>
void outManagerLink(LinkListM L);//录入管理员信息<br>
void managerLogCheck(LinkListM L);//管理员登录检测 <br>
void managerSystem(LinkListM L);//管理员操作 <br>
void manageInfoM(LinkListM L);//管理员信息管理 <br>
void changePasswordM(LinkListM L);//管理员修改密码 <br>
void changeEMailM(LinkListM L);//管理员修改邮箱 <br>
void manageOrderM(LinkListM);//管理员订单管理 <br>
LinkListOrder creatOrderList();//读取历史订单 <br>
LinkListOrderM creatMarketOrderList(LinkListOrder L1, LinkListM L2);//筛选出属于该超市的订单 <br>
void checkOrderM(LinkListOrderM);//确认订单 <br>
void statisticsOrderM(LinkListOrderM L,LinkListCommodity L1);//统计订单 <br>
LinkListStatistic creatStatisticList(LinkListOrderM L1, LinkListCommodity L2);//统计商品销量及利润 <br>
float totalVolume(LinkListOrderM L);//计算总营业额 <br>
void sortAmount(LinkListStatistic L);//根据销量排序<br>
void sortVolume(LinkListStatistic L);//根据营业额排序 <br>
void sortProfit(LinkListStatistic L);//根据利润排序 <br>
void printShortOrder(LinkListStatistic L);//显示商品，销量及利润 <br>
void determineComodity(LinkListCommodity L);//判断畅销，滞销情况 <br>
<br>
void manageCommodityM(LinkListM);//管理员商品管理 <br>
LinkListCommodity creatCommodityLink();//商品信息读取 <br>
void outCommodityLink(LinkListCommodity);//录入商品信息 <br>
void checkCommodity(LinkListCommodity,LinkListM);//显示商品信息 <br>
void addNewCommodity(LinkListCommodity,LinkListM);//添加新商品信息 <br>
void confirmAdd(LinkListCommodity,LinkListCommodity,LinkListCommodity,LinkListM );//确认，修改，退出录入新商品 <br>
void fixCommodity(LinkListCommodity);//修改新商品信息 <br>
int checkUserID(char *str);//检验ID是否合法 <br>
int checkTelNum(char *str);//检验TelNum是否合法<br>
int checkEMail(char *str);//检验EMail是否合法<br>
int checkCommodityID(char *str, LinkListCommodity L);//检验商品ID是否合法<br>
### 3、系统数据结构描述<br>
系统处理的数据为字符（char）类型和整数（int）类型，这些数据的存储形式为ASCII码。<br>
<br>
## 二、模块详细设计<br>
### 1、功能概述<br>
用户模块功能：<br>
登录功能：负责核对ID及密码。<br>
查询商品信息功能：查询商品号、商品所属超市、商品售价、商品销量、商品库存、折扣率、折后价格、折扣开始及结束时间。<br>
用户购买功能：输入用户ID和密码登录系统后，即可实现购物、查询订单等操作。<br>
商品筛选功能：包括根据商品号号查询商品；根据价格查询商品；根据折扣率查询商品；根据超市名称查询商品。<br>
个人信息管理功能：对用户个人信息中的邮箱、电话、密码、地址进行修改。<br>
取消订单功能：在未付款前取消自己的订单。<br>
查询购买记录功能：查询购物后的订单，查看用户曾经的购物记录。<br>
管理员模块功能<br>
登录功能：负责核对ID及密码。<br>
查询用户订单信息情况功能：查询管理员所在超市所有的订单信息。<br>
查询本超市内所有货物功能：查询本公司所有正在售卖的商品信息。<br>
添加新商品功能：添加新的商品，在商品发布之前可以进行修改。<br>
修改商品功能：在发布添加的新商品之前，管理员可以进行修改，或者取消添加。<br>
个人管理信息功能：允许管理员修改个人信息中的密码和邮箱。<br>
## 2.各功能模块处理流程：<br>
登录模块：使用者首先选择身份，选择用户便进入用户模块，实现用户功能，选择管理员便进入管理员模块，实现管理员功能。<br>
<br>
用户功能模块：用户登录完成后可选择进入。进入后用户可查询到所有商品信息。并可以选择根据商品名查询商品；根据超市名查询商品；根据是否有折扣筛选商品。可分别根据价格和销量排序。还可进行系统推荐。最后实现购买。完成操作后返回上一级操作。<br>
<br>
管理个人信息模块：用户登录完成后可选择进入。进入后用户可选择更改邮箱、电话或密码。在修改结束之前可以选择确认修改、重新修改或者取消修改。操作完成后返回上一级操作。<br>
<br>
已购订单查询模块：用户登录完成后可选择进入。进入后用户可查询到所有已购订单信息。操作完成后返回上一级操作。<br>
<br>
管理订单模块：管理员登录完成后可选择进入。进入后可查询、统计订单信息。查询用户订单情况可查询到管理员所在超市的所有订单信息。统计用户订单信息可分别根据销量、营业额排序所有商品信息。操作完成后返回上一级操作。<br>
<br>
添加商品模块：管理员登录完成后可选择进入。进入后可查询商品、添加新商品。查询商品信息可查询到管理员所在公司的所有商品信息。添加商品可添加一个新的商品，系统会判断新商品名，ID与已有商品名,ID是否相同，若相同将返回重新添加商品信息。添加后可选择提交、修改及取消。提交后商品添加成功。修改可根据用户选择对单一信息修改，修改后重新进行检查。可取消添加商品<br>
<br>
管理个人信息：管理员登录完成后可选择进入。进入后可修改管理员个人信息中的邮箱、密码。在修改结束之前可以选择确认修改、重新修改或者取消修改。操作完成后返回上一级操作。<br>
模块接口要求：<br>
void userLog();<br>
接口名：userLog()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：顾客登录<br>
<br>
void addUser(LinkListC L);<br>
接口名：addUser()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：添加顾客账号<br>
<br>
void outUserLink(LinkListC L);<br>
接口名：outUserLink()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：创建包含所有顾客信息的链表<br>
<br>
void logCheck(LinkListC L);<br>
接口名：logCheck()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：检查顾客登陆信息<br>
<br>
void userSystem(LinkListC L);<br>
接口名：userSystem()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：顾客系统<br>
<br>
void managePerInfo(LinkListC L);<br>
接口名：managePerInfo ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：管理个人信息<br>
<br>
void changeTel(LinkListC L);<br>
接口名：changeTel ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：检查电话格式<br>
<br>
void changePassword(LinkListC L);<br>
接口名：changePassword ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：更改个人密码<br>
<br>
void changeEMail(LinkListC L);<br>
接口名：changeEMail ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：更改邮箱<br>
<br>
void changeAddress(LinkListC L);<br>
接口名：changeAddress ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：更改地址<br>
<br>
void searchCommodity(LinkListC);//<br>
接口名：searchCommodity ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：查询商品<br>
<br>
void byCommodityName(LinkListCommodity);<br>
接口名：byCommodityName ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按照商品名查询<br>
<br>
void byMarketName(LinkListCommodity);<br>
接口名：byMarketName ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按照超市名查询<br>
<br>
void byDiscount(LinkListCommodity); <br>
接口名：byDiscount ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按照是否有折扣查询商品<br>
<br>
void afterSearch(LinkListCommodity,LinkListC);<br>
接口名：afterSearch ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：查询后的操作<br>
<br>
void sortBySaleAmount(LinkListCommodity);//<br>
接口名：sortBySaleAmount ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按照销量排序<br>
<br>
void sortBySalePrice(LinkListCommodity);<br>
接口名：sortBySalePrice ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按照售价排序<br>
<br>
void recommendation(LinkListCommodity);<br>
接口名：recommendation ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：推荐商品<br>
<br>
void chooseCommodity(LinkListCommodity, LinkListC);<br>
接口名：chooseCommodity ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：选择商品<br>
<br>
void afterChoose(LinkListOrder,LinkListC,LinkListCommodity);<br>
接口名：afterChoose ()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：选择之后的操作<br>
<br>
int payOrder(LinkListC, LinkListOrder);//<br>
接口名：payOrder（）<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：整数(int)类型<br>
接口作用：支付订单<br>
void userOldOrder(LinkListC);<br>
接口名：add_information()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：用户旧的订单<br>
<br>
void outUserNewOrder(LinkListOrder);<br>
接口名：outUserNewOrder<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：将用户的新订单添加到订单文件中<br>
<br>
void managerLog();<br>
接口名：managerLog()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：管理员登陆<br>
LinkListM createManagerLink();<br>
接口名：createManagerLink()<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：//创建包含所有管理员信息的链表<br>
void addManager(LinkListM L)<br>
接口名：addManager(LinkListM L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：添加管理员<br>
void outManagerLink(LinkListM L)<br>
接口名：outManagerLink(LinkListM L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：输出包含所有管理员信息的链表到文档中<br>
void managerLogCheck(LinkListM L)<br>
接口名： managerLogCheck(LinkListM L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：管理员登陆检查<br>
void managerSystem(LinkListM L)<br>
接口名：managerSystem(LinkListM L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：管理员系统<br>
void manageInfoM(LinkListM L)<br>
接口名：manageInfoM(LinkListM L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：管理员信息<br>
void changePasswordM(LinkListM L);//<br>
接口名：changePasswordM(LinkListM L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：更改密码<br>
void changeEMailM(LinkListM L)<br>
接口名：changeEMailM(LinkListM L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：更改邮箱<br>
void manageOrderM(LinkListM)<br>
接口名：manageOrderM(LinkListM)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：管理所属超市的全部订单<br>
void checkOrderM(LinkListOrderM)<br>
接口名：checkOrderM(LinkListOrderM)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：查看管理员所属超市的所有订单<br>
void statisticsOrderM(LinkListOrderM L,LinkListCommodity L1)<br>
接口名：statisticsOrderM(LinkListOrderM L,LinkListCommodity L1)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：统计订单信息<br>
void sortAmount(LinkListStatistic L)<br>
接口名：sortAmount(LinkListStatistic L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按销量排序<br>
void sortVolume(LinkListStatistic L)<br>
接口名：sortVolume(LinkListStatistic L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按营业额排序<br>
void sortProfit(LinkListStatistic L)<br>
接口名：sortProfit(LinkListStatistic L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按利润排序<br>
void printShortOrder(LinkListStatistic L)<br>
接口名：printShortOrder(LinkListStatistic L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：打印订单信息<br>
void determineComodity(LinkListCommodity L)<br>
接口名：determineComodity(LinkListCommodity L)<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：判断商品状态<br>
<br>
void manageCommodityM(LinkListM);<br>
函数名：manageCommodity<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：管理商品<br>
<br>
void outCommodityLink(LinkListCommodity);<br>
函数名：outCommodityLink<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：录入商品信息<br>
<br>
void checkCommodity(LinkListCommodity,LinkListM);<br>
函数名：checkCommodity<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：查询商品<br>
<br>
void addNewCommodity(LinkListCommodity,LinkListM);<br>
函数名：addNewCommodity<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：添加新商品<br>
<br>
VoidconfirmAdd(LinkListCommodity,LinkListCommodity,LinkListCommodity,LinkListM );<br>
函数名：confirmAdd<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：确认添加商品<br>
<br>
void fixCommodity(LinkListCommodity);<br>
函数名：fixCommodity<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：修改商品信息<br>
<br>
void manageOrderM(LinkListM);<br>
函数名：managerOrderM<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：管理订单<br>
<br>
void checkOrderM(LinkListOrderM);<br>
函数名：checkOrderM<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：查询订单<br>
<br>
void statisticsOrderM(LinkListOrderM L,LinkListCommodity L1);<br>
函数名：statisticOrderM<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：统计订单<br>
<br>
void sortAmount(LinkListStatistic L);<br>
函数名：sortAmount（）<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按销量排序<br>
<br>
void sortVolume(LinkListStatistic L);<br>
函数名：sortVolume（）<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按价格排序<br>
<br>
void sortProfit(LinkListStatistic L);<br>
函数名：sortProfit（）<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：按销量排序<br>
<br>
void printShortOrder(LinkListStatistic L);<br>
函数名：printShortOrder（）<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：打印订单信息<br>
<br>
void determineComodity(LinkListCommodity L);<br>
函数名：determineComodity（）<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：确定商品<br>
<br>
个人信息管理功能<br>
void manageInfoM(LinkListM L);<br>
函数名：manageInfoM（）<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：管理个人信息<br>
<br>
void changePasswordM(LinkListM L);<br>
函数名：changePasswordM（）<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：修改密码<br>
<br>
Void changeEMailM(LinkListM L);<br>
函数名：changeEmailM（）<br>
接口参数：处理全局结构数组，包含字符（char）类型和整数（int）类型；<br>
返回值：空值<br>
接口作用：修改邮箱<br>
<br>
### 3、功能的边界情况描述及处理方法<br>
程序使用scanf、fscanf、gets函数，各功能的边界情况均用空格和换行（回车）判断，当到达边界时，及读入停止，输出打印时各参数用空格或\t代替，\n用来换行。<br>
<br>
<br>


