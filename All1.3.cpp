#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct customer{
	char CustomerID[11];
	char Name[30];
	int Sex; //0 male, 1 female
	char Tel[15];
	char PassWord[15];
	char EMail[30];
	char Address[80];
	float Account;
	struct customer *next;®
}customer;

typedef struct Manager{
	char ManagerID[11];
	char PassWord[15];
	char MarketName[30];//common with commodity
	char Name[30];
	char EMail[30];
	struct Manager *next;
}Manager;

typedef struct Commodity{
	char CommodityNum[7];//common with order
	char Name[30];
	char MarketName[30];//common with manager
	float SalePrice;
	float NetPrice;
	float DiscountPrice;
	int SaleAmount;
	int Inventory;
	char DiscountStartTime[20];
	char DiscountEndTime[20]; 
	struct Commodity *next;
}Commodity;

typedef struct Order{
	char OrderNum[100];
	char CustomerID[11];
	char MarketName[30];//common with manager
	char BuyTime[18];
	char CommodityNum[7];//common with commodity
	char CommodityName[20];
	int Amount;
	float SalePrice;
	float TotalPrice;
	struct Order *next;
}Order;

typedef struct marketOrder{
	char OrderNum[100];
	char CustomerID[11];
    char BuyTime[18];
    char MarketName[30];
	char CommodityNum[7];
	char CommodityName[20];
	int Amount;
	float SalePrice;
    float TotalPrice;
    struct marketOrder *next;
}marketOrder; //operate the orders owned manager's market

typedef struct statisticMarket{
    char CommodityName[20];
    char CommodityNum[7];//common
    int SaleAmount;//++
    float NetPrice;//const
    float TotalPrice;//++
    float Profit;//calculate
    struct statisticMarket *next;
}statisticMarket; 

typedef struct customer *LinkListC;
typedef struct Manager *LinkListM;
typedef struct Commodity *LinkListCommodity;
typedef struct Order *LinkListOrder;
typedef struct marketOrder *LinkListOrderM;
typedef struct statisticMarket *LinkListStatistic;

void userLog();
void addUser(LinkListC L);
LinkListC createUserLink();
void outUserLink(LinkListC L);
void logCheck(LinkListC L);

void userSystem(LinkListC L);
void managePerInfo(LinkListC L);
void changeTel(LinkListC L);
void changePassword(LinkListC L);
void changeEMail(LinkListC L);
void changeAddress(LinkListC L);

void searchCommodity(LinkListC);
void byCommodityName(LinkListCommodity);
void byMarketName(LinkListCommodity);
void byDiscount(LinkListCommodity); //discountprice==saleprice
void afterSearch(LinkListCommodity,LinkListC);
void sortBySaleAmount(LinkListCommodity);
void sortBySalePrice(LinkListCommodity);
void recommendation(LinkListCommodity);
void chooseCommodity(LinkListCommodity, LinkListC);
void afterChoose(LinkListOrder,LinkListC,LinkListCommodity);
int payOrder(LinkListC, LinkListOrder);
void userOldOrder(LinkListC);
void outUserNewOrder(LinkListOrder);
LinkListOrder creatOrderList();
LinkListCommodity creatCommodityLink();

char time();

void managerLog();
//read manager list 
LinkListM createManagerLink();//ok

//update manager database
void addManager(LinkListM L);
void outManagerLink(LinkListM L);

//manager login
void managerLogCheck(LinkListM L);

//manager system
void managerSystem(LinkListM L);

//manager system --> manage personal information//ok
void manageInfoM(LinkListM L);
void changePasswordM(LinkListM L);
void changeEMailM(LinkListM L);

//manager system --> manage orders
void manageOrderM(LinkListM);
LinkListOrder creatOrderList();
LinkListOrderM creatMarketOrderList(LinkListOrder L1, LinkListM L2);
void checkOrderM(LinkListOrderM);
void statisticsOrderM(LinkListOrderM L,LinkListCommodity L1);
LinkListStatistic creatStatisticList(LinkListOrderM L1, LinkListCommodity L2);
float totalVolume(LinkListOrderM L);
void sortAmount(LinkListStatistic L);
void sortVolume(LinkListStatistic L);
void sortProfit(LinkListStatistic L);
void printShortOrder(LinkListStatistic L);
void determineComodity(LinkListCommodity L);


//manager system --> manage commidities//ok
void manageCommodityM(LinkListM);
LinkListCommodity creatCommodityLink();//ok
void outCommodityLink(LinkListCommodity);//ok
void checkCommodity(LinkListCommodity,LinkListM);//ok
void addNewCommodity(LinkListCommodity,LinkListM);//ok
void confirmAdd(LinkListCommodity,LinkListCommodity,LinkListCommodity,LinkListM );//ok
void fixCommodity(LinkListCommodity);

//check format
int checkUserID(char *str);
int checkTelNum(char *str);
int checkEMail(char *str);
int checkCommodityID(char *str, LinkListCommodity L);

int main() {
	
	int choice;
	
	printf("========================\n");
	printf("|       Welcome        |\n");
	printf("|     1.Customer       |\n");
	printf("|     2.Manager        |\n");
	printf("|     3.Exit           |\n");
	printf("========================\n");
	printf("Choice: ");
	scanf("%d",&choice);
	
	if(choice==1){
		userLog();
	}
	else if(choice==2){
		managerLog();
	}
	else if(choice==3){
		exit(1);
	}
	else{
		system("cls");
		main();
	}
	return 0;
}

/*
  ===============================
  this part belongs to customer
  Customer System ok
  ===============================
*/

void userLog(){
	int choice;
	LinkListC user;
	user = createUserLink(); 
	system("cls");
	printf("---------------------------\n");
	printf("|   1.New User Login.     |\n");//ok
	printf("|   2.Existing User Login.|\n");//ok
	printf("|   3.Return              |\n");
	printf("|   4.Quit                |\n");
	printf("--------------------------\n\n");
	printf("Please enter your choice: ");
	
	scanf("%d",&choice);
	 
	if(choice == 1){
		system("cls");
		addUser(user);
		system("cls");
		outUserLink(user);
		printf("Success! Please re-login!\n");
		logCheck(user);
		outUserLink(user);
	}
	
	else if(choice == 2){
		system("cls");
		logCheck(user);
		outUserLink(user);
	}
	else if(choice==3){
		system("cls");
		main();
	}
	else if(choice == 4){
		system("cls");
		exit(0);
	}
	
	else{
		userLog();
	}
}
void addUser(LinkListC L){
	LinkListC newUser;
	LinkListC p;
	p=L; 
	while(p->next!=NULL){
		p=p->next;
	}
	
	newUser=(LinkListC)malloc(sizeof(customer));

	printf("Sign Up:\n");
	printf("NAME:");
	scanf("%s",newUser->Name);
	printf("ID(6-10 number mix word):");
	scanf("%s",newUser->CustomerID);
	printf("PASSWARD:");
	scanf("%s",newUser->PassWord);
	printf("TEL:");
	scanf("%s",newUser->Tel);
	printf("SEX(0=male,1=female):");
	scanf("%d",&newUser->Sex);
	printf("EMAIL:");
	scanf("%s",newUser->EMail);
	printf("ADDRESS:");
	scanf("%s",newUser->Address);
	printf("ACCOUNT MONEY:");
	scanf("%f",&newUser->Account);
	newUser->next=NULL;
	if(checkUserID(newUser->CustomerID)&&checkEMail(newUser->EMail)&&checkTelNum(newUser->Tel))
		p->next=newUser;
	else{
		//system("cls");
		printf("WRONG!,TRY AGAIN!\n");
		addUser(L);
	} 
}
void outUserLink(LinkListC L){
   LinkListC p=L->next;
   FILE *fp =fopen("customer.txt","w");
   if(fp==NULL)
   {
       printf("open fail!");
   }
    
   while(p){
   		fprintf(fp,"%s\n",p->CustomerID);
   		fprintf(fp,"%s\n",p->Name);
   		fprintf(fp,"%d\n",p->Sex);
   		fprintf(fp,"%s\n",p->Tel);
   		fprintf(fp,"%s\n",p->PassWord);
   		fprintf(fp,"%s\n",p->EMail);
   		fprintf(fp,"%s\n",p->Address);
   		fprintf(fp,"%f\n",p->Account);
   		p=p->next;
   }
	
	fclose(fp);
}
void logCheck(LinkListC L){
	
	char ID[10];
	char password[15]; 
	int a=0;
	
	printf("ID:");
	scanf("%s",ID);
	printf("Password:");
	scanf("%s",password);
	
	LinkListC p,currentUser;
	p=L->next;
	
	while(p){
		if(strcmp(ID,p->CustomerID)==0){
			a=1;
			if(strcmp(password,p->PassWord)==0){
				printf("Success!\n");
				system("pause");
				system("cls");
				currentUser=p;
				userSystem(currentUser);
				break;
			}
			else{
				printf("Wrong! Try Again!\n");
				logCheck(L);
			}	
		}
		p=p->next;
	}
	
	if(!a){
		printf("Your ID does not exist!\n");
		system("pause");
		userLog();
	}
		
} 
void userSystem(LinkListC L){
	system("cls");
	int choice;
	
	printf("-------------------------------------\n");
	printf("|    1.Commodity Search             |\n");
	printf("|    2.Manage Personal Information  |\n");//ok
	printf("|    3.Manage orders                |\n");
	printf("|    4.Return                       |\n");
	printf("-------------------------------------\n\n");
	printf("Please enter your choice: ");
	scanf("%d",&choice);
	
	if(choice==1){
		system("cls");
		searchCommodity(L);
	}
	
	else if(choice==2){
		managePerInfo(L);
	}
	
	else if(choice==3){
		userOldOrder(L);
		system("pause");
		userSystem(L);
	}
	
	else if(choice==4){
		userLog();
	}
	
	else{
		printf("WRONG!\n");
		userSystem(L);
	}
}
void managePerInfo(LinkListC L){
	
	system("cls");
	int choice;
	
	printf("-----------------------------\n");
	printf("|      1.Change Tel         |\n");
	printf("|      2.Change Password    |\n");
	printf("|      3.Change e-Mail      |\n");
	printf("|      4.Change Address     |\n");
	printf("|      5.Return             |\n");
	printf("-----------------------------\n\n");
	printf("Please enter your choice: ");
	scanf("%d",&choice);
	
	if(choice == 1){
		changeTel(L);
		managePerInfo(L);
	}
	
	else if(choice == 2){
		changePassword(L);
		managePerInfo(L);
	}
	
	else if(choice == 3){
		changeEMail(L);
		managePerInfo(L);
	}
	
	else if(choice == 4){
		changeAddress(L);
		managePerInfo(L);
	}
	
	else if(choice ==5){
		userSystem(L);
	}
	
	else{
		system("cls");
		printf("WRONG!\n");
		system("pause");
		managePerInfo(L);
	}
}	
void changeTel(LinkListC L){
	printf("Change Tel:\n");
	printf("Old TEL: %s\n",L->Tel);
	printf("Please enter your new telephone number(11 numbers):\n");
	scanf("%s",L->Tel);
	if(!checkTelNum(L->Tel)){
		printf("E-Mail format is not right!\n");
		changeTel(L);
	}
}
void changePassword(LinkListC L){
	printf("Change Password:\n");
	printf("Please enter your new password:\n");
	scanf("%s",L->PassWord);
	printf("Change Successfully!\n");
}
void changeEMail(LinkListC L){
	printf("Change e-Mail:\n");
	printf("Old e-Mail: %s\n",L->EMail);
	printf("Please enter your new e-Mail:\n");
	scanf("%s",L->EMail);
	if(!checkEMail(L->EMail)){
		printf("E-Mail format is not right!\n");
		changeEMail(L);
	}
}
void changeAddress(LinkListC L){
	printf("Change Address:\n");
	printf("Old Address: %s\n",L->Address);
	printf("Please enter your new address:\n");
	scanf("%s",L->Address);
}
void searchCommodity(LinkListC currentUser){
	int choice;
	LinkListCommodity allCommodity;
	allCommodity=creatCommodityLink();

	printf("----------------------------------------------\n");
	printf("|         1.Search by commodity's name       |\n");//allCommodity
	printf("|         2.Search by market's name          |\n");//allCommodity
	printf("|         3.Look discount commodity          |\n");//allCommodity
	printf("|         4.Sort by sale price               |\n");//allCommodity
	printf("|         5.Sort by sale amount              |\n");//allCommodity
	printf("|         6.Recommendation                   |\n");
	printf("|         7.Return                           |\n");
	printf("----------------------------------------------\n");
	printf("Please enter your choice: ");
	scanf("%d",&choice);

	if(choice==1){
		byCommodityName(allCommodity);//LinkListCommodity
		afterSearch(allCommodity,currentUser);
	}
	else if(choice==2){
		byMarketName(allCommodity);//LinkListCommodity
		afterSearch(allCommodity,currentUser);
	}
	else if(choice==3){
		byDiscount(allCommodity);//LinkListCommodity
		afterSearch(allCommodity,currentUser);
	}
	else if(choice==4){
		sortBySalePrice(allCommodity);
		afterSearch(allCommodity,currentUser);
	}
	else if(choice==5){
		sortBySaleAmount(allCommodity);
		afterSearch(allCommodity,currentUser);
	}
	else if(choice==6){
		recommendation(allCommodity);
		afterSearch(allCommodity,currentUser);
	} 
	else if(choice==7){
		userSystem(currentUser);
	}
	else{
		printf("Wrong!\n");
	}
}

/*----
	search module ok
*/
void byCommodityName(LinkListCommodity allCommodity){

	char name[30];
	LinkListCommodity p;

	system("cls");
	printf("Please enter the commodity's name: ");
	scanf("%s",name);

	p=allCommodity->next;
	
	printf("Commodity information:\n");
	printf("CommodityNumber      Name       MarketName      SalePrice      DisCount      Start      End      Inventory \n");
	
	while(p){
		if(strcmp(name,p->Name)==0){
			
			printf("%s      ",p->CommodityNum);
			printf("%s      ",p->Name);
			printf("%s      ",p->MarketName);
			printf("%.2f      ",p->SalePrice);
			printf("%.2f      ",p->DiscountPrice);
			printf("%s      ",p->DiscountStartTime);
			printf("%s      ",p->DiscountEndTime);
			printf("%d\n",p->Inventory);
		}
		p=p->next;
	}
}
void byMarketName(LinkListCommodity allCommodity){
	
	char name[30];
	LinkListCommodity p;
	
	printf("Please enter the market's name: ");
	scanf("%s",name);
	
	p=allCommodity->next;
	
	printf("Commodity information:\n");
	printf("CommodityNumber      Name       MarketName      SalePrice      DisCount      Start      End      Inventory \n");
	
	while(p){
		if(strcmp(name,p->MarketName)==0){
			printf("%s      ",p->CommodityNum);
			printf("%s      ",p->Name);
			printf("%s      ",p->MarketName);
			printf("%.2f      ",p->SalePrice);
			printf("%.2f      ",p->DiscountPrice);
			printf("%s      ",p->DiscountStartTime);
			printf("%s      ",p->DiscountEndTime);
			printf("%d\n",p->Inventory);
		}
		p=p->next;
	}
}
void byDiscount(LinkListCommodity allCommodity){
	LinkListCommodity p;
	p=allCommodity->next;
	
	printf("Commodity information:\n");
	printf("CommodityNumber      Name       MarketName      SalePrice      DisCount      Start      End      Inventory \n");
	
	while(p){
		if(p->DiscountPrice!=p->SalePrice){
			printf("%s      ",p->CommodityNum);
			printf("%s      ",p->Name);
			printf("%s      ",p->MarketName);
			printf("%.2f      ",p->SalePrice);
			printf("%.2f      ",p->DiscountPrice);
			printf("%s      ",p->DiscountStartTime);
			printf("%s      ",p->DiscountEndTime);
			printf("%d\n",p->Inventory);
		}
		p=p->next;
	}
}
void sortBySaleAmount(LinkListCommodity allCommodity){
	int i,j;
    Commodity *temp;
    temp=(LinkListCommodity)malloc(sizeof(Commodity));
    LinkListCommodity p = allCommodity;
    int count = 0;
    while(p->next != NULL)
    {
        count++;
        p = p->next;
    }

    for(i=0;i<count-1;i++)
    {
        p = allCommodity->next;
        for(j=0;j<count-i-1;j++)
        {
            if(p->SaleAmount > p->next->SaleAmount)
            {
                strcpy(temp->CommodityNum,p->CommodityNum);
                strcpy(p->CommodityNum,p->next->CommodityNum);
                strcpy(p->next->CommodityNum,temp->CommodityNum);
               
                strcpy(temp->Name,p->Name);
                strcpy(p->Name,p->next->Name);
				strcpy(p->next->Name,temp->Name);
				
				strcpy(temp->MarketName,p->MarketName);
                strcpy(p->MarketName,p->next->MarketName);
				strcpy(p->next->MarketName,temp->MarketName);
				
				strcpy(temp->DiscountStartTime,p->DiscountStartTime);
                strcpy(p->DiscountStartTime,p->next->DiscountStartTime);
				strcpy(p->next->DiscountStartTime,temp->DiscountStartTime);

				strcpy(temp->DiscountEndTime,p->DiscountEndTime);
                strcpy(p->DiscountEndTime,p->next->DiscountEndTime);
				strcpy(p->next->DiscountEndTime,temp->DiscountEndTime);
				
				temp->SalePrice=p->SalePrice;
                p->SalePrice=p->next->SalePrice;
				p->next->SalePrice=temp->SalePrice;
				
				temp->NetPrice=p->NetPrice;
                p->NetPrice=p->next->NetPrice;
				p->next->NetPrice=temp->NetPrice;
				
				temp->DiscountPrice=p->DiscountPrice;
                p->DiscountPrice=p->next->DiscountPrice;
                p->next->DiscountPrice=temp->DiscountPrice;
				
				temp->SaleAmount=p->SaleAmount;
                p->SaleAmount=p->next->SaleAmount;
                p->next->SaleAmount=temp->SaleAmount;
                
                temp->Inventory=p->Inventory;
                p->Inventory=p->next->Inventory;
				p->next->Inventory=temp->Inventory;
            }
            p = p->next;
        }
    }
    p = allCommodity->next;
    printf("Commodity information:\n");
	printf("CommodityNumber      Name       MarketName      SalePrice      DisCount      Start      End      Inventory \n");
    while(p){
		printf("%s\t",p->CommodityNum);
		printf("%s\t",p->Name);
		printf("%s\t",p->MarketName);
		printf("%.2f\t",p->SalePrice);
		printf("%.2f\t",p->DiscountPrice);
		printf("%s\t",p->DiscountStartTime);
		printf("%s\t",p->DiscountEndTime);
		printf("%d\n",p->Inventory);
		p=p->next;
	}
}
void sortBySalePrice(LinkListCommodity allCommodity){
	int i,j;
    Commodity *temp;
    temp=(LinkListCommodity)malloc(sizeof(Commodity));
    LinkListCommodity p = allCommodity;
    int count = 0;
    while(p->next != NULL)
    {
        count++;
        p = p->next;
    }

    for(i=0;i<count-1;i++)
    {
        p = allCommodity->next;
        for(j=0;j<count-i-1;j++)
        {
            if(p->SalePrice > p->next->SalePrice)
            {
                strcpy(temp->CommodityNum,p->CommodityNum);
                strcpy(p->CommodityNum,p->next->CommodityNum);
                strcpy(p->next->CommodityNum,temp->CommodityNum);
               
                strcpy(temp->Name,p->Name);
                strcpy(p->Name,p->next->Name);
				strcpy(p->next->Name,temp->Name);
				
				strcpy(temp->MarketName,p->MarketName);
                strcpy(p->MarketName,p->next->MarketName);
				strcpy(p->next->MarketName,temp->MarketName);
				
				strcpy(temp->DiscountStartTime,p->DiscountStartTime);
                strcpy(p->DiscountStartTime,p->next->DiscountStartTime);
				strcpy(p->next->DiscountStartTime,temp->DiscountStartTime);

				strcpy(temp->DiscountEndTime,p->DiscountEndTime);
                strcpy(p->DiscountEndTime,p->next->DiscountEndTime);
				strcpy(p->next->DiscountEndTime,temp->DiscountEndTime);
				
				temp->SalePrice=p->SalePrice;
                p->SalePrice=p->next->SalePrice;
				p->next->SalePrice=temp->SalePrice;
				
				temp->NetPrice=p->NetPrice;
                p->NetPrice=p->next->NetPrice;
				p->next->NetPrice=temp->NetPrice;
				
				temp->DiscountPrice=p->DiscountPrice;
                p->DiscountPrice=p->next->DiscountPrice;
                p->next->DiscountPrice=temp->DiscountPrice;
				
				temp->SaleAmount=p->SaleAmount;
                p->SaleAmount=p->next->SaleAmount;
                p->next->SaleAmount=temp->SaleAmount;
                
                temp->Inventory=p->Inventory;
                p->Inventory=p->next->Inventory;
				p->next->Inventory=temp->Inventory;
            }
            p = p->next;
        }
    }
    p = allCommodity->next;
    printf("Commodity information:\n");
	printf("CommodityNumber      Name       MarketName      SalePrice      DisCount      Start      End      Inventory \n");
    while(p){
		printf("%s\t",p->CommodityNum);
		printf("%s\t",p->Name);
		printf("%s\t",p->MarketName);
		printf("%.2f\t",p->SalePrice);
		printf("%.2f\t",p->DiscountPrice);
		printf("%s\t",p->DiscountStartTime);
		printf("%s\t",p->DiscountEndTime);
		printf("%d\n",p->Inventory);
		p=p->next;
	}
}

void recommendation(LinkListCommodity allCommodity){
	int i,j;
    Commodity *temp;
    temp=(LinkListCommodity)malloc(sizeof(Commodity));
    LinkListCommodity p = allCommodity;
    int count = 0;
    while(p->next != NULL)
    {
        count++;
        p = p->next;
    }

    for(i=0;i<count-1;i++)
    {
        p = allCommodity->next;
        for(j=0;j<count-i-1;j++)
        {
        	float m=(p->SalePrice-p->DiscountPrice)/p->SalePrice; 
        	float n=(p->next->SalePrice-p->next->DiscountPrice)/p->next->SalePrice;
            if(n > m)
            {
                strcpy(temp->CommodityNum,p->CommodityNum);
                strcpy(p->CommodityNum,p->next->CommodityNum);
                strcpy(p->next->CommodityNum,temp->CommodityNum);
               
                strcpy(temp->Name,p->Name);
                strcpy(p->Name,p->next->Name);
				strcpy(p->next->Name,temp->Name);
				
				strcpy(temp->MarketName,p->MarketName);
                strcpy(p->MarketName,p->next->MarketName);
				strcpy(p->next->MarketName,temp->MarketName);
				
				strcpy(temp->DiscountStartTime,p->DiscountStartTime);
                strcpy(p->DiscountStartTime,p->next->DiscountStartTime);
				strcpy(p->next->DiscountStartTime,temp->DiscountStartTime);

				strcpy(temp->DiscountEndTime,p->DiscountEndTime);
                strcpy(p->DiscountEndTime,p->next->DiscountEndTime);
				strcpy(p->next->DiscountEndTime,temp->DiscountEndTime);
				
				temp->SalePrice=p->SalePrice;
                p->SalePrice=p->next->SalePrice;
				p->next->SalePrice=temp->SalePrice;
				
				temp->NetPrice=p->NetPrice;
                p->NetPrice=p->next->NetPrice;
				p->next->NetPrice=temp->NetPrice;
				
				temp->DiscountPrice=p->DiscountPrice;
                p->DiscountPrice=p->next->DiscountPrice;
                p->next->DiscountPrice=temp->DiscountPrice;
				
				temp->SaleAmount=p->SaleAmount;
                p->SaleAmount=p->next->SaleAmount;
                p->next->SaleAmount=temp->SaleAmount;
                
                temp->Inventory=p->Inventory;
                p->Inventory=p->next->Inventory;
				p->next->Inventory=temp->Inventory;
            }
            p = p->next;
        }
    }
    p = allCommodity->next;
    printf("Commodity information:\n");
	printf("CommodityNumber      Name       MarketName      SalePrice      DisCount      Start      End      Inventory  DiscountRatio\n");
    while(p){
		printf("%s\t",p->CommodityNum);
		printf("%s\t",p->Name);
		printf("%s\t",p->MarketName);
		printf("%.2f\t",p->SalePrice);
		printf("%.2f\t",p->DiscountPrice);
		printf("%s\t",p->DiscountStartTime);
		printf("%s\t",p->DiscountEndTime);
		printf("%d\t",p->Inventory);
		printf("%.2f%%\t\n",(p->SalePrice-p->DiscountPrice)/p->SalePrice);
		p=p->next;
	}
}

/*----
	purchase ok
*/
void afterSearch(LinkListCommodity allCommodity,LinkListC currentUser){

	int choice;
	printf("---------------------------------\n");
	printf("|      1.Purchase Commodity     |\n");//allcommodity, currentuser
	printf("|      2.Return                 |\n");//allcommodity, currentuser
	printf("---------------------------------\n");
	printf("Please enter your choice: ");
	scanf("%d",&choice);

	if(choice==1){
		chooseCommodity(allCommodity,currentUser);
	}
	else if(choice==2){
		//return
		system("cls");
		searchCommodity(currentUser);
	}
	else{
		printf("Wrong!\n");
		afterSearch(allCommodity,currentUser);
	}
}
void chooseCommodity(LinkListCommodity allCommodity, LinkListC currentUser){
//creat new order
	char commodityID[7];
	int amount;
	int a=0;
	LinkListOrder newOrder;
	LinkListCommodity p;
	p=allCommodity->next;
	newOrder=(LinkListOrder)malloc(sizeof(Order));
	printf("Enter Commodity ID:");
	scanf("%s",commodityID);
	printf("Enter Amount: ");
	scanf("%d",&amount);

	while(p){
		if(strcmp(commodityID,p->CommodityNum)==0){	
			if(p->Inventory >= amount){
				//add order information
				//buy success -> write in txt
				//when search, read all order from txt
				time_t tt;
				tt=time(NULL);
				strftime(newOrder->BuyTime,80,"%Y:%m:%d:%H:%M",localtime(&tt));
				strcpy(newOrder->OrderNum,currentUser->CustomerID);
				strcat(newOrder->OrderNum,newOrder->BuyTime);
				strcpy(newOrder->CustomerID,currentUser->CustomerID);
				strcpy(newOrder->MarketName,p->MarketName);
				strcpy(newOrder->CommodityNum,p->CommodityNum);
				strcpy(newOrder->CommodityName,p->Name);
				newOrder->Amount=amount;
				newOrder->SalePrice=p->SalePrice;
				newOrder->TotalPrice=amount*p->SalePrice;
				newOrder->next=NULL;	
				afterChoose(newOrder,currentUser,allCommodity);
			}
			a=1;
		}
		p=p->next;
	}
	if(!a){
		printf("No ID\n");
		afterSearch(allCommodity,currentUser);
	}
}
void afterChoose(LinkListOrder newOrder,LinkListC currentUser,LinkListCommodity allCommodity){
	
	int choice;
	LinkListCommodity p=allCommodity->next;
	printf("---------------------------\n");
	printf("|       1.confirm & pay   |\n");
	printf("|       2.cancel          |\n");
	printf("---------------------------\n");
	printf("Choice:");
	scanf("%d",&choice); 
	
	if(choice==1){
		if(payOrder(currentUser,newOrder)){
			printf("Success!\n");
			//add order to doc
			//check commodity's amount
			while(p){
				if(strcmp(newOrder->CommodityNum,p->CommodityNum)==0){
					p->Inventory=p->Inventory-newOrder->Amount;
					p->SaleAmount=p->SaleAmount+newOrder->Amount;
				}
				p=p->next;	
			}
			outCommodityLink(allCommodity);
			outUserNewOrder(newOrder);
			allCommodity=creatCommodityLink();
			afterSearch(allCommodity,currentUser);
		}
		else{
			printf("failed!\n");
			afterSearch(allCommodity,currentUser);
		}
	}
	
	else if(choice==2){
		free(newOrder); 
		afterSearch(allCommodity,currentUser);
	}
	
	else{
		//afterChoose(newOrder,currentUser,allCommodity);
	}
}
int payOrder(LinkListC currentUser, LinkListOrder newOrder){
	
	char password[15];
	printf("Please enter your pay password:");
	scanf("%s",password);

	for(int i=0;i<3;i++){
		if(strcmp(currentUser->PassWord,password)==0){
			//check money
			if(currentUser->Account < newOrder->TotalPrice){
				printf("You money limited!\n");
				return 0;
			}
			currentUser->Account =currentUser->Account-newOrder->TotalPrice;
			LinkListC allUser=createUserLink();
			LinkListC p;
			p=allUser->next;
			while(p){
				if(strcmp(p->CustomerID,currentUser->CustomerID)==0){
					p->Account=currentUser->Account;
				}
				p=p->next;
			}
			outUserLink(allUser);
			return 1;
		}
		else{
			printf("Wrong,try again!\n");
			printf("Please enter your pay password:");
			scanf("%s",password);
		}
	}
	return 0;
}
/*-------
	check old orders ok
*/
void userOldOrder(LinkListC currentUser){
	LinkListOrder allOrder;
	LinkListOrder p;
	allOrder=creatOrderList();
	p=allOrder->next;
	printf("Order information:\n");
	printf("(OrderNumber  Market  BuyTime  CommodityNumber  CommodityName  Amount  SalePrice  TotalPrice)\n\n");
	while(p){
		//compare User ID this is ok
		if(strcmp(p->CustomerID,currentUser->CustomerID)==0){
			printf("%s\t\t",p->OrderNum);
			printf("%s\t",p->MarketName);//ok
			printf("%s\t",p->BuyTime);
			printf("%s\t",p->CommodityNum);//ok
			printf("%s\t",p->CommodityName);//ok
			printf("%d\t",p->Amount);//ok
			printf("%.2f\t",p->SalePrice);//ok
			printf("%.2f\n",p->TotalPrice);
		}
		p=p->next;
	}
}

void outUserNewOrder(LinkListOrder newOrder){
	
	LinkListOrder p;
	p=newOrder;
	
	FILE *fp=fopen("order.txt","a");
	if(fp==NULL){
		printf("open failed");
	}

	fprintf(fp,"%s\n",p->OrderNum);
	fprintf(fp,"%s\n",p->CustomerID);
	fprintf(fp,"%s\n",p->MarketName);
	fprintf(fp,"%s\n",p->BuyTime);
	fprintf(fp,"%s\n",p->CommodityNum);
	fprintf(fp,"%s\n",p->CommodityName);
	fprintf(fp,"%d\n",p->Amount);
	fprintf(fp,"%f\n",p->SalePrice);
	fprintf(fp,"%f\n",p->TotalPrice);
	
	fclose(fp);
}

/*
  ====================================
  This part belongs to marktet manager
  Manager system
  ====================================
*/

void managerLog(){
	int choice;
	LinkListM manager;
	//read manager.txt & add manager information into managerlist
	manager = createManagerLink();
	system("cls");
	printf("---------------------------\n");
	printf("|        1.Sign up        |\n");//ok
	printf("|        2.Login          |\n");//ok
	printf("|        3.Return         |\n");
	printf("--------------------------\n\n");
	printf("Please enter your choice: ");
	
	scanf("%d",&choice);
	
	if(choice == 1){
		system("cls");
		addManager(manager);//ok
		system("cls");
		outManagerLink(manager);//ok
		printf("Success! Please re-login!\n");
		managerLogCheck(manager);
		outManagerLink(manager);
	}
	
	else if(choice == 2){
		system("cls");
		managerLogCheck(manager);
		outManagerLink(manager);
	}
	
	else if(choice == 3){
		main();
	}
	
	else{
		system("cls");
		printf("WRONG NUMBER!\n");
		managerLog();
	}
}
void addManager(LinkListM L){
	LinkListM newManager;
	LinkListM p;
	p=L; 
	while(p->next!=NULL){
		p=p->next;
	}
	
	newManager=(LinkListM)malloc(sizeof(Manager));

	printf("Sign Up:\n");
	printf("MARKET NAME:");
	scanf("%s",newManager->MarketName);
	printf("NAME:");
	scanf("%s",newManager->Name);
	printf("ID(6-10 number mix word):");
	scanf("%s",newManager->ManagerID);
	printf("PASSWARD:");
	scanf("%s",newManager->PassWord);
	printf("EMAIL:");
	scanf("%s",newManager->EMail);
	newManager->next=NULL;
	
	if(checkUserID(newManager->ManagerID)&&checkEMail(newManager->EMail))
		p->next=newManager;
	else{
		//system("cls");
		printf("WRONG!,TRY AGAIN!\n");
		addManager(L);
	} 
}
void outManagerLink(LinkListM L){
   LinkListM p=L->next;
   FILE *fp =fopen("manager.txt","w");
   if(fp==NULL)
   {
       printf("Open failed!");
   }
 
   while(p){
   		fprintf(fp,"%s\n",p->ManagerID);
   		fprintf(fp,"%s\n",p->PassWord);
   		fprintf(fp,"%s\n",p->MarketName);
   		fprintf(fp,"%s\n",p->Name);
   		fprintf(fp,"%s\n",p->EMail);
   		p=p->next;
   }
	
	fclose(fp);
}
void managerLogCheck(LinkListM L){
	
	char ID[11];
	char password[15]; 
	int a=0;
	
	printf("ID:");
	scanf("%s",ID);
	printf("Password:");
	scanf("%s",password);
	
	LinkListM p,currentManager;
	p=L->next;
	
	while(p){
		if(strcmp(ID,p->ManagerID)==0){
			a=1;
			if(strcmp(password,p->PassWord)==0){
				printf("Success!\n");
				currentManager=p;
				managerSystem(currentManager);
				break;
			}
			else{
				system("cls");
				printf("Wrong! Try Again!\n");
				managerLogCheck(L);//L does not change
			}	
		}
		p=p->next;
	}
	
	if(!a)
		printf("Your ID does not exist!\n");
} 
/*----------
	manager system
	L-->currentManager
*/
void managerSystem(LinkListM L){
	
	int choice;
	LinkListCommodity C=creatCommodityLink();
	
	system("cls");
	printf("----------------------------------------\n");
	printf("|       1.Manage Orders                |\n");//not ok
	printf("|       2.Manage Commodities           |\n");//ok
	printf("|    	3.Manage Personal Information  |\n");//ok
	printf("|       4.Return                       |\n");//ok
	printf("----------------------------------------\n\n");
	printf("Please enter your choice: ");
	scanf("%d",&choice);
	
	if(choice==1){
		manageOrderM(L);
		managerSystem(L);
	}
	
	else if(choice==2){
		manageCommodityM(L);//current manager
		managerSystem(L);
	}
	
	else if(choice==3){
		manageInfoM(L);//ok
		managerSystem(L);
	}
	
	else if(choice==4){
		managerLog();
	}
	
	else{
		printf("WRONG!\n");
		managerSystem(L);
	}
}
/*-------
	manager system --> manage personal information
*/
void manageInfoM(LinkListM L){
	
	int choice;
	
	system("cls");
	printf("-----------------------------\n");
	printf("|      1.Change Password    |\n");//ok
	printf("|      2.Change e-Mail      |\n");//ok
	printf("|      3.Return             |\n");//ok
	printf("-----------------------------\n\n");
	printf("Please enter your choice: ");
	scanf("%d",&choice);
	
	if(choice == 1){
		changePasswordM(L);
		manageInfoM(L);
	}
	
	else if(choice == 2){
		changeEMailM(L);
		manageInfoM(L);
	}
	
	else if(choice == 3){
		managerSystem(L);
	}
	
	else{
		printf("WRONG!\n");
		manageInfoM(L);
	}
}	
void changePasswordM(LinkListM L){
	system("cls");
	printf("Change Password:\n");
	printf("Please enter your new password:\n");
	scanf("%s",L->PassWord);
	printf("Change Successfully!\n");
}
void changeEMailM(LinkListM L){
	system("cls");
	printf("Change e-Mail:\n");
	//printf("Old e-Mail: %s\n",L->EMail);
	printf("Please enter your new e-Mail:\n");
	scanf("%s",L->EMail);
	if(!checkEMail(L->EMail)){
		printf("E-Mail format is not right!\n");
		changeEMailM(L);
	}
}
/*-------
	manager system --> manage commodities
*/
void manageCommodityM(LinkListM manager){

    int choice;
    LinkListCommodity commodity;
    commodity=creatCommodityLink();

	//system("cls");
    printf("------------------------------------\n");
    printf("|        1.Check Commodities       |\n");
    printf("|        2.Add a New Commodity     |\n");
    printf("|        3.Return                  |\n");
    printf("------------------------------------\n\n");
    printf("Please enter your choice:");

    scanf("%d",&choice);

    if(choice==1){
        checkCommodity(commodity,manager);
        manageCommodityM(manager);
    }

    else if(choice==2){
        printf("Add a New Commodity:\n");
        addNewCommodity(commodity,manager);
        outCommodityLink(commodity);
        manageCommodityM(manager);
    }

    else if(choice==3){
        managerSystem(manager);
    }

    else{
        printf("WRONG NUMBER!\n");
        manageCommodityM(manager);
    }

}
void outCommodityLink(LinkListCommodity L){

    LinkListCommodity p=L->next;
    FILE *fp =fopen("commodity.txt","w");
    if(fp==NULL)
    {
        printf("Fail!");
    }

    while(p){
        fprintf(fp,"%s\n",p->CommodityNum);
        fprintf(fp,"%s\n",p->Name);
        fprintf(fp,"%s\n",p->MarketName);
        fprintf(fp,"%f\n",p->SalePrice);
        fprintf(fp,"%f\n",p->NetPrice);
        fprintf(fp,"%f\n",p->DiscountPrice);
        fprintf(fp,"%d\n",p->SaleAmount);
        fprintf(fp,"%d\n",p->Inventory);
        fprintf(fp,"%s\n",p->DiscountStartTime);
        fprintf(fp,"%s\n",p->DiscountEndTime);
        p=p->next;
    }
     
     fclose(fp);
}
void checkCommodity(LinkListCommodity L1, LinkListM L2){
    
    LinkListCommodity p;
    p=L1->next;

    printf("Name      ID       SalePrice      NetPrice      DiscountPrice      SaleAmount      Inventory\n");
    while(p){
        if(strcmp(L2->MarketName,p->MarketName)==0){
            printf("%s       ",p->Name);
            printf("%s       ",p->CommodityNum);
            printf("%.2f     ",p->SalePrice); 
            printf("%.2f     ",p->NetPrice); 
            printf("%.2f     ",p->DiscountPrice); 
            printf("%d       ",p->SaleAmount);
            printf("%d       ",p->Inventory);       
            printf("\n");  
        }

        p=p->next;
    }
}
//L2->manager
void addNewCommodity(LinkListCommodity L1, LinkListM L2){

    /*
     * checkCommodityName()   
     * checkCommodityID()	
     * checkCommodityInventory()	
     * checkTimeFormat()
     * confirmAdd(LinkListCommodity)
     * fixCommodity()
     */
    
    LinkListCommodity newCommodity;
    LinkListCommodity p;
    
    p=L1;
    
    while(p->next!=NULL){
        p=p->next;    
    }

    newCommodity=(LinkListCommodity)malloc(sizeof(Commodity));

    printf("Name:");
    scanf("%s",newCommodity->Name);
    printf("Commodity ID:");
    scanf("%s",newCommodity->CommodityNum);
    strcpy(newCommodity->MarketName,L2->MarketName);
    printf("SalePrice:");
    scanf("%f",&newCommodity->SalePrice);
    printf("NetPrice:");
    scanf("%f",&newCommodity->NetPrice);
    printf("DiscountPrice:");
    scanf("%f",&newCommodity->DiscountPrice);
    newCommodity->SaleAmount=0;
    printf("Inventory:");
    scanf("%d",&newCommodity->Inventory);
    printf("DiscountStartTime:");
    scanf("%s",newCommodity->DiscountStartTime);
    printf("DiscountEndTime:");
    scanf("%s",newCommodity->DiscountEndTime);
    newCommodity->next=NULL;
    
    if(!checkCommodityID(newCommodity->CommodityNum, L1)){
    	printf("ID is wrong!\n");
    	addNewCommodity(L1,L2);
	}
	//pass p and newCommodity
 	if(newCommodity->Inventory<=0)
	{
	 	printf("Inventory must be greater than 0!\n");
    	addNewCommodity(L1,L2);
	}
	p=L1;
	while(p->next!=NULL){
		if(strcpy(p->next->Name,newCommodity->Name)==0){
			printf("Commodity name repeat!\n");
			addNewCommodity(L1,L2);
			break; 
		}
		p=p->next;
	} 
	 
	 
	confirmAdd(p,newCommodity,L1,L2);
	
}
/*
	L1->p
	new->newCommodity
*/
void confirmAdd(LinkListCommodity L1,LinkListCommodity newCommodity, LinkListCommodity allCommodity,LinkListM manager){
	
	int choice;
    
    printf("------------------------------\n");
    printf("|         1.Fix              |\n");
    printf("|         2.Cancel           |\n");
    printf("|         3.Publish          |\n");
    printf("------------------------------\n");
    printf("Please enter your choice:");
    scanf("%d",&choice);

    if(choice==1){
        fixCommodity(newCommodity);
        confirmAdd(L1,newCommodity,allCommodity,manager);
        manageCommodityM(manager);
    }

    else if(choice==2){
        free(newCommodity);
        manageCommodityM(manager);
    }

    else if(choice==3){
        L1->next=newCommodity;
        outCommodityLink(allCommodity);
        manageCommodityM(manager);
    }

    else{
        printf("Please enter the right number:");
        confirmAdd(L1,newCommodity,allCommodity,manager);
    }
}  
void fixCommodity(LinkListCommodity newCommodity){
    /*
    print information of new commodity
    */

    int choice;

    printf("-----------------------------------------\n");
    printf("|Choose which one you want to fix:      |\n");
    printf("|      1.Name                           |\n");
    printf("|      2.Commodity ID                   |\n");
    printf("|      3.SalePrice                      |\n");
    printf("|      4.NetPrice:                      |\n");
    printf("|      5.DiscountPrice:                 |\n");
    printf("|      6.Inventory:                     |\n");
    printf("|      7.DiscountStartTime:             |\n");
    printf("|      8.DiscountEndTime:               |\n");
    printf("|      9.OK                             |\n");
    printf("-----------------------------------------\n\n");
    printf("Please enter your choice:");
    scanf("%d",&choice);

    if(choice==1){
        printf("Name:");
        scanf("%s",newCommodity->Name);
        fixCommodity(newCommodity);
    }

    else if(choice==2){
        printf("Commodity ID:");
        scanf("%s",newCommodity->CommodityNum);
        fixCommodity(newCommodity);
    }

    else if(choice==3){
        printf("SalePrice:");
        scanf("%f",&newCommodity->SalePrice);
        fixCommodity(newCommodity);
    }

    else if(choice==4){
        printf("NetPrice:");
        scanf("%f",&newCommodity->NetPrice);
        fixCommodity(newCommodity);
    }

    else if(choice==5){
        printf("DiscountPrice:");
        scanf("%f",&newCommodity->DiscountPrice);
        fixCommodity(newCommodity);                
    }

    else if(choice==6){
        printf("Inventory:");
        scanf("%d",&newCommodity->Inventory);
        fixCommodity(newCommodity);
    }

    else if(choice==7){
        printf("DiscountStartTime:");
        scanf("%s",newCommodity->DiscountStartTime);
        fixCommodity(newCommodity);
    }

    else if(choice==8){
        printf("DiscountEndTime:");
        scanf("%s",newCommodity->DiscountEndTime);
        fixCommodity(newCommodity);
    }

    else if(choice==9){

    }

    else{
        printf("Wrong!\n");
    }
	
}
/*----------
	check format
	return 0 is wrong
	return 1 is right
*/
int checkUserID(char *str){
     //1 right 0 wrong
     int length=strlen(str);
     int num=0;
	 int letter=0;
	
     if(5<length<11){
         for(int i=0; i<length;i++){
         	if(str[i]>='0'&&str[i]<='9')
	 			num++;
	 		if(str[i]>='a'&&str[i]<='z' || str[i]>='A'&&str[i]<='Z')
		 		letter++; 
             if(str[i]>='0'&&str[i]<='9' || str[i]>='a'&&str[i]<='z' || str[i]>='A'&&str[i]<='Z'){
                 continue;
             }
             else{
                printf("ID combine letter and number.\n");
                return 0;
             }
         }
         if(num==0||letter==0){
         	printf("ID combine letter and number.\n");
            return 0;
		 }
         return 1;
     }
     else{
         printf("ID between 6-10.\n");
         return 0;
     }
}
int checkTelNum(char *str){
    int length=strlen(str);
    if(length==11){
        for(int i=0; i<length; i++){
            if(str[i]>='0'&&str[i]<='9')
            	continue;
            else{
                printf("Telephone number must be all numbers.\n");
                return 0;
            }
        }
        return 1;
    }
    else{
        printf("Telephone number has 11 numbers.\n");
        return 0;
    }
}
int checkEMail(char *str){
	int length=strlen(str);
    int atTime=0;
    int dotTime=0;
    int a,b;

    //atTime must be 1

    if(str[0]!='@'||str[0]>='0'&&str[0]<='9' || str[0]>='a'&&str[0]<='z' || str[0]>='A'&&str[0]<='Z'){
        for(int i=1; i<length; i++){
            if(str[i]=='@'){
                atTime++;
                a=i;
            }
            
            if(str[i]=='.'){
                dotTime++;
                b=i;
            }

            if(str[i]>='0'&&str[i]<='9' || str[i]>='a'&&str[i]<='z' || str[i]>='A'&&str[i]<='Z' || str[i]=='@' || str[i]=='.')
                continue;
            else{
            	printf("1\n");
            	return 0;
			}
                
        }
        
        if(atTime!=1 || dotTime!=1){
        	printf("2\n");
        	return 0;
        }
        else{
            for(int i=1; i<length; i++){
                if(str[i]=='@')
                    a=i;
                
                if(str[i]=='.')
                    b=i;
            }

            if((b-a)<1)
            {
            	printf("3\n");
            	return 0;
			}
                
            else
                return 1;
        }

    }
    else{
    	printf("4\n");
        return 0;
    }
}
int checkCommodityID(char *str, LinkListCommodity L){
     int length=strlen(str);

     if(length==6){
        for(int i=0; i<2; i++){
            if(str[i]>='a'&&str[i]<='z' || str[i]>='A'&&str[i]<='Z'){
                continue;
            }
            else
                return 0;
        }
        for(int i=2; i<length; i++){
            if(str[i]>='0'&&str[i]<='9'){
                continue;
            }
            else
                return 0;
        }
        LinkListCommodity p;
        p=L->next;

        while(p){
            if(strcmp(str,p->CommodityNum)==0){
                printf("Repeat!\n");
                return 0;
            }
            p=p->next;
        }

        return 1;
     }

     else
        return 0;
     
}
 /*----------------
 	manage orders ---manager
*/
void manageOrderM(LinkListM L){

    int choice;
    LinkListOrder order;
    LinkListOrderM orderMarket;
    LinkListCommodity C; 
    order=creatOrderList();//all order
    orderMarket=creatMarketOrderList(order,L);
    C=creatCommodityLink();

    printf("--------------------------------\n");
    printf("|        1.Check Orders        |\n");
    printf("|        2.Statistics Orders   |\n");
    printf("|        3.Return              |\n");
    printf("--------------------------------\n\n");
    printf("Please enter your choice:");

    scanf("%d",&choice);

    if(choice==1){
    	orderMarket=creatMarketOrderList(order,L);
        checkOrderM(orderMarket);
        manageOrderM(L);
    }

    else if(choice==2){
        statisticsOrderM(orderMarket, C);
        manageOrderM(L);
    }

    else if(choice==3){
        managerSystem(L);
    }

    else{
        printf("WRONG NUMBER!\n");
        manageOrderM(L);
    }
}
void checkOrderM(LinkListOrderM L){

    LinkListOrderM p;
    p=L->next;
    
    printf("NO       CommodityNumber    CommodityName      Amount     SalePrice      TotalPrice      BuyTime\n");

    while(p){
        printf("%s    ",p->OrderNum);
		printf("%s    ",p->CommodityNum);
		printf("%s    ",p->CommodityName);
		printf("%d    ",p->Amount);
		printf("%.2f    ",p->SalePrice);
		printf("%.2f    ",p->TotalPrice);
		printf("%s\n",p->BuyTime);        
        p=p->next;
    }
}
void statisticsOrderM(LinkListOrderM L,LinkListCommodity L1){
    /*
     * totalVolume //ok
     * creatStatisticList //ok
     * paixu
     * calculateProfit
     * determineComodity
     * L1-->all Commodity
     */
    LinkListStatistic statistic=creatStatisticList(L,L1);
    LinkListStatistic p;
    
	p=statistic;
    printf("Total Volume: %.2f\n", totalVolume(L));
    printf("Order sorted in sale amount:\n");
    sortAmount(p);
	printShortOrder(p);
    
    p=statistic;
   
    printf("Order sorted in volume:\n");
    sortVolume(p);
    printShortOrder(statistic);
    
    p=statistic;
    sortProfit(p);
    printf("Profit min:\n");
    p=statistic;
    if(p->next!=NULL){
    	printf("CommodityName   CommodityNum     SaleAmount        Profit\n");
    	printf("%s    ",p->next->CommodityName);
    	printf("%s    ",p->next->CommodityNum);
    	printf("%d    ",p->next->SaleAmount);
    	printf("%f\n",p->next->Profit);
	}
    
    p=statistic;
    while(p->next)
        p=p->next;
    printf("Profit max:\n");
    printf("CommodityName   CommodityNum     SaleAmount        Profit\n");
    printf("%s    ",p->CommodityName);
    printf("%s    ",p->CommodityNum);
    printf("%d    ",p->SaleAmount);
    printf("%f\n",p->Profit);
    determineComodity(L1);
}
float totalVolume(LinkListOrderM L){
    float total=0;
    LinkListOrderM p;

    p=L->next;

    while(p){
        total=total+p->TotalPrice;
        p=p->next;
    }

    return total;
}
void printShortOrder(LinkListStatistic L){
    LinkListStatistic p;
    p=L->next;

    printf("CommodityName   CommodityNum     SaleAmount        Profit\n");
    while(p){
        printf("%s    ",p->CommodityName);
        printf("%s    ",p->CommodityNum);
        printf("%d    ",p->SaleAmount);
        printf("%.2f\n",p->Profit);
        p=p->next;
    }
}
void determineComodity(LinkListCommodity L){
    LinkListCommodity p;
    p=L->next;

    printf("CommodityNumber   CommoditName   State\n");
    while(p){
        if(L->SaleAmount > 2*L->Inventory){
            printf("%s      ",p->CommodityNum);
            printf("%s      ",p->Name);
            printf("Need to purchase\n");
        }

        else if(L->Inventory > 2*L->SaleAmount){
            printf("%s      ",p->CommodityNum);
            printf("%s      ",p->Name);
            printf("Unsalable\n");
        }
        else{
            printf("%s      ",p->CommodityNum);
            printf("%s      ",p->Name);
            printf("Normal\n");
        }
        p=p->next;
    }
} 

/*
  ======================================
	This part is creat relative linklist
	Read relatice elements form .txt
	(Common part)
  ======================================
*/
LinkListC createUserLink(){
    LinkListC head =(LinkListC)malloc(sizeof(customer));
    LinkListC p;//whole list
    LinkListC q;//new node
    p=q=head;
    
	FILE *fp= fopen("customer.txt","r");
    if(fp==NULL)
    {
        printf("open failed!");
        
    }
    
    q=(LinkListC)malloc(sizeof(customer));
    
    while(fscanf(fp,"%s",q->CustomerID)!=EOF){
    	fscanf(fp,"%s",q->Name);
    	fscanf(fp,"%d",&q->Sex);
    	fscanf(fp,"%s",q->Tel);
    	fscanf(fp,"%s",q->PassWord);
    	fscanf(fp,"%s",q->EMail);
    	fscanf(fp,"%s",q->Address);
    	fscanf(fp,"%f",&q->Account);
    	p->next=q;
    	p=p->next;	
    	q=(LinkListC)malloc(sizeof(customer));
	}
	 
    p->next=NULL;
    
    fclose(fp);
    return head;
}
LinkListOrder creatOrderList(){
    LinkListOrder head=(LinkListOrder)malloc(sizeof(Order));
    LinkListOrder p;//whole list
    LinkListOrder q;//new node
    p=q=head;

    FILE *fp=fopen("order.txt","r");
    if(fp==NULL){
        printf("Open file, fail!\n");
    }

    q=(LinkListOrder)malloc(sizeof(Order));

    while(fscanf(fp,"%s",q->OrderNum)!=EOF){
        fscanf(fp,"%s",q->CustomerID);
    	fscanf(fp,"%s",q->MarketName);
        fscanf(fp,"%s",q->BuyTime);
        fscanf(fp,"%s",q->CommodityNum);
        fscanf(fp,"%s",q->CommodityName);
        fscanf(fp,"%d",&q->Amount);
        fscanf(fp,"%f",&q->SalePrice);
        fscanf(fp,"%f",&q->TotalPrice);
        p->next=q;
        p=p->next;
        q=(LinkListOrder)malloc(sizeof(Order));
    }

    p->next=NULL;
    
    fclose(fp);
    return head;
}
LinkListCommodity creatCommodityLink(){
    LinkListCommodity head=(LinkListCommodity)malloc(sizeof(Commodity));
    LinkListCommodity p;//whole list
    LinkListCommodity q;//new node
    p=q=head;

    FILE *fp=fopen("commodity.txt","r");
    if(fp==NULL){
        printf("Open file, fail!\n");
    }

    q=(LinkListCommodity)malloc(sizeof(Commodity));

    while(fscanf(fp,"%s",q->CommodityNum)!=EOF){
        fscanf(fp,"%s",q->Name);
        fscanf(fp,"%s",q->MarketName);
        fscanf(fp,"%f",&q->SalePrice);
        fscanf(fp,"%f",&q->NetPrice);
        fscanf(fp,"%f",&q->DiscountPrice);
        fscanf(fp,"%d",&q->SaleAmount);
        fscanf(fp,"%d",&q->Inventory);
        fscanf(fp,"%s",q->DiscountStartTime);
        fscanf(fp,"%s",q->DiscountEndTime);
        p->next=q;
        p=p->next;
        q=(LinkListCommodity)malloc(sizeof(Commodity));
    }

    p->next=NULL;

    fclose(fp);
    return head;
}
//L1->market's order L2->all commodities
//creat LinkListStatistic
LinkListStatistic creatStatisticList(LinkListOrderM L1, LinkListCommodity L2){
   
    int a;
    LinkListStatistic head=(LinkListStatistic)malloc(sizeof(statisticMarket));
    LinkListStatistic p,q;
    p=head;
    LinkListOrderM m;//ordermarket
    LinkListCommodity n=L2->next;//commodity
    q=(LinkListStatistic)malloc(sizeof(statisticMarket));
   	q->SaleAmount=0;
    q->TotalPrice=0;
    
    while(n){
    	a=0;
    	m=L1->next;
    	
        while(m){
            if(strcmp(n->CommodityNum, m->CommodityNum)==0){
            	//printf("1");
                strcpy(q->CommodityName,n->Name);
                strcpy(q->CommodityNum,n->CommodityNum);
                q->SaleAmount=q->SaleAmount+m->Amount;
                q->NetPrice=n->NetPrice;
                q->TotalPrice=q->TotalPrice+m->TotalPrice;   
				a=1;            
            }
            m=m->next;
        }
        
        if(a){
        	q->Profit=q->TotalPrice-q->SaleAmount*q->NetPrice;//add determine
			p->next=q;
        	p=p->next;
        	q=(LinkListStatistic)malloc(sizeof(statisticMarket));
        	q->SaleAmount=0;
    		q->TotalPrice=0;
		}
		n=n->next;
    }

    p->next=NULL;
    return head;
}
//L2->manager L1->allorder return->this market's order
LinkListOrderM creatMarketOrderList(LinkListOrder L1, LinkListM L2){
    LinkListOrderM head=(LinkListOrderM)malloc(sizeof(marketOrder));
    LinkListOrderM p;//whole list
    LinkListOrderM q;//new node
    LinkListOrder m;
    
    p=q=head;
    m=L1;
    q=(LinkListOrderM)malloc(sizeof(marketOrder));

    while(m){
        if(strcmp(L2->MarketName,m->MarketName)==0){
            strcpy(q->OrderNum,m->OrderNum);
            strcpy(q->CustomerID,m->CustomerID);
            strcpy(q->MarketName,m->MarketName);
            strcpy(q->BuyTime,m->BuyTime);
            strcpy(q->CommodityNum,m->CommodityNum);
            strcpy(q->CommodityName,m->CommodityName);
            q->Amount=m->Amount;
            q->SalePrice=m->SalePrice;
            q->TotalPrice=m->TotalPrice;
            p->next=q;
        	p=p->next;
        	q=(LinkListOrderM)malloc(sizeof(Order));
        }
        m=m->next;
    }
    p->next=NULL;

	/*p=head->next;
	while(p){
		printf("%s\n",p->OrderNum);
		printf("%s\n",p->CustomerID);
		p=p->next;
	}
	 */
    return head;
}
//ok
LinkListM createManagerLink(){
    LinkListM head =(LinkListM)malloc(sizeof(Manager));
    LinkListM p;//whole list
    LinkListM q;//new node
    p=q=head;
    
	FILE *fp= fopen("manager.txt","r");
    if(fp==NULL)
    {
        printf("open failed!\n");
        
    }
    
    q=(LinkListM)malloc(sizeof(Manager));
    
    while(fscanf(fp,"%s",q->ManagerID)!=EOF){
    	fscanf(fp,"%s",q->PassWord);
		fscanf(fp,"%s",q->MarketName);
    	fscanf(fp,"%s",q->Name);
    	fscanf(fp,"%s",q->EMail);
    	p->next=q;
    	p=p->next;	
    	q=(LinkListM)malloc(sizeof(Manager));
	}
	 
    p->next=NULL;
    
    fclose(fp);
    return head;
}



void sortAmount(LinkListStatistic L){
    int i,j;
    LinkListStatistic temp;
    LinkListStatistic p = L;
    int count = 0;
    while(p->next != NULL)
    {
        count++;
        p = p->next;
    }

	temp=(LinkListStatistic)malloc(sizeof(statisticMarket));

    for(i=0;i<count-1;i++)
    {
        p = L->next;
        for(j=0;j<count-i-1;j++)
        {
           if(p->SaleAmount > p->next->SaleAmount){
            strcpy(temp->CommodityName,p->CommodityName);
            strcpy(p->CommodityName,p->next->CommodityName);
            strcpy(p->next->CommodityName,temp->CommodityName);
           
            strcpy(temp->CommodityNum,p->CommodityNum);
            strcpy(p->CommodityNum,p->next->CommodityNum);
            strcpy(p->next->CommodityNum,temp->CommodityNum);
            
            temp->SaleAmount=p->SaleAmount;
            p->SaleAmount=p->next->SaleAmount;
            p->next->SaleAmount=temp->SaleAmount;
            
            temp->NetPrice=p->NetPrice;
            p->NetPrice=p->next->NetPrice;
            p->next->NetPrice=temp->NetPrice;
            
            temp->TotalPrice=p->TotalPrice;
            p->TotalPrice=p->next->TotalPrice;
            p->next->TotalPrice=temp->TotalPrice;

            temp->Profit=p->Profit;
            p->Profit=p->next->Profit;
            p->next->Profit=temp->Profit;
           }
            p = p->next;
        }
    }
}
void sortVolume(LinkListStatistic L){
    int i,j;
    LinkListStatistic temp;
    LinkListStatistic p = L; 
    int count = 0;
    while(p->next != NULL)
    {
        count++;
        p = p->next;
    }
    
    temp=(LinkListStatistic)malloc(sizeof(statisticMarket));

    for(i=0;i<count-1;i++)
    {
        p = L->next;
        for(j=0;j<count-i-1;j++)
        {
            if(p->TotalPrice > p->next->TotalPrice)
            {
                strcpy(temp->CommodityName,p->CommodityName);
                strcpy(p->CommodityName,p->next->CommodityName);
                strcpy(p->next->CommodityName,temp->CommodityName);
               
                strcpy(temp->CommodityNum,p->CommodityNum);
                strcpy(p->CommodityNum,p->next->CommodityNum);
                strcpy(p->next->CommodityNum,temp->CommodityNum);
                
                temp->SaleAmount=p->SaleAmount;
                p->SaleAmount=p->next->SaleAmount;
                p->next->SaleAmount=temp->SaleAmount;
                
                temp->NetPrice=p->NetPrice;
                p->NetPrice=p->next->NetPrice;
                p->next->NetPrice=temp->NetPrice;
                
                temp->TotalPrice=p->TotalPrice;
                p->TotalPrice=p->next->TotalPrice;
                p->next->TotalPrice=temp->TotalPrice;

                temp->Profit=p->Profit;
                p->Profit=p->next->Profit;
                p->next->Profit=temp->Profit;
            }
            p = p->next;
        }
    }
}
void sortProfit(LinkListStatistic L){
    int i,j;
    LinkListStatistic temp;
    LinkListStatistic p = L;
    int count = 0;
    while(p->next != NULL)
    {
        count++;
        p = p->next;
    }
    
    temp=(LinkListStatistic)malloc(sizeof(statisticMarket));
	
    for(i=0;i<count-1;i++)
    {
        p = L->next;
        for(j=0;j<count-i-1;j++)
        {
            if(p->Profit > p->next->Profit)
            {
                strcpy(temp->CommodityName,p->CommodityName);
                strcpy(p->CommodityName,p->next->CommodityName);
                strcpy(p->next->CommodityName,temp->CommodityName);
               
                strcpy(temp->CommodityNum,p->CommodityNum);
                strcpy(p->CommodityNum,p->next->CommodityNum);
                strcpy(p->next->CommodityNum,temp->CommodityNum);
                
                temp->SaleAmount=p->SaleAmount;
                p->SaleAmount=p->next->SaleAmount;
                p->next->SaleAmount=temp->SaleAmount;
                
                temp->NetPrice=p->NetPrice;
                p->NetPrice=p->next->NetPrice;
                p->next->NetPrice=temp->NetPrice;
                
                temp->TotalPrice=p->TotalPrice;
                p->TotalPrice=p->next->TotalPrice;
                p->next->TotalPrice=temp->TotalPrice;

                temp->Profit=p->Profit;
                p->Profit=p->next->Profit;
                p->next->Profit=temp->Profit;
            }
            p = p->next;
        }
    }
     
}
