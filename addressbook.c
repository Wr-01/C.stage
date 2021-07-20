#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<assert.h>

#define MAX 200

//通讯录管理系统
//结构体：人（联系人的属性）
typedef struct person {
	char name[1024];  //1024=1k
	char phone[1024];
	char address[1024];
}person;
//结构体：通讯录（属性：包含联系人个数，联系人数组，容量）
typedef struct addressbook {
	int size;           //实际联系人个数
	person* adpersons;  //改成指针形式，通过动态内存管理的方式来进行初始化 
	int capacity;       //容量:表示当前人结构体person的空间最大容量
}addressbook;

//初始化通讯录函数（显示的申请内存空间）
void init(addressbook* adp) {
	adp->size = 0;
	adp->capacity = 200; //相当于初始化定义通讯录最大容量200个联系人<=>MAX
	//动态申请内存空间
	adp->adpersons = (person*)malloc(adp->capacity * sizeof(person));

	//memset(adp->adpersons, 0, sizeof(person)*adp->capacity);//初始化整个通讯录
}

//通讯录菜单
int menu() {
	printf("================================================\n");
	printf("============         通讯录       ==============\n");
	printf("============  1.显示联系人功能    ==============\n");
	printf("============  2.添加联系人功能    ==============\n");
	printf("============  3.查找联系人功能    ==============\n");
	printf("============  4.修改联系人功能    ==============\n");
	printf("============  5.删除联系人功能    ==============\n");
	printf("============  6.清空联系人功能    ==============\n");
	printf("============  0.退出通讯录功能    ==============\n");
	printf("================================================\n");
	int select = 0;
	printf("请输入你选择的功能：");
	scanf("%d", &select);
	return select;
}

//创建一个实现不同功能的函数指针
typedef void (*func)(addressbook* adp);

//创建一组函数完成保存到文件以及从文件加载数据
//实现把通讯录数据保存到文件中
void save(addressbook* adp) {
	//1.打开文件
	FILE* f = fopen("D:/22.txt", "w");
	if (f == NULL) {
		perror("文件打开失败");
		return;
	}
	//2.写入（保存通讯录数据）
	//for (int i = 0; i < adp->size; i++) {
	//	person* p = &adp->adpersons[i];
	//	fwrite(p, sizeof(person), 1, f);
	//}
	fwrite(adp->adpersons, sizeof(person), adp->size, f);
	//3.关闭文件
	fclose(f);
}
//从文件中加载数据到通讯录里
void load(addressbook* adp) {
	//1.打开文件
	FILE* f = fopen("D:/22.txt", "r");
	if (f == NULL) {
		printf("当前文件尚未创建！\n");
		return;
	}
	//2.读取数据(注意读取过程中可能需要扩容，故最好使用循环，边为扩容)
	while (1) {
		person fperson = { 0 };
		size_t len = fread(&fperson, sizeof(person), 1, f);
		if (len == 0) {
			printf("读取成功！\n");
			break;
		}
		//把读取的person数组中的数据一个个加到通讯录结构体联系人的变量里去
		if (adp->size >= adp->capacity) {
			//内存不够，需要先扩容
			person* old = adp->adpersons;
			adp->capacity += 100;
			adp->adpersons = (person*)malloc(adp->capacity * sizeof(person));
			memcpy(adp->adpersons, old, sizeof(person) * adp->size);

			free(old);//释放旧空间
		}
		//赋值数据
		adp->adpersons[adp->size] = fperson;
		adp->size++;
	}
	//3.关闭文件
	fclose(f);
}

//显示联系人函数
void showPerson(addressbook* adp) {
	assert(adp != NULL);
	if (adp->size == 0) {
		printf("该通讯录没有联系人！\n");
		return;
	}
	printf("所有联系人信息如下：\n");
	for (int i = 0; i < adp->size; i++) {
		person* p = &adp->adpersons[i];
		printf("[%d] %s\t%s\t%s\n", i, p->name, p->phone, p->address);
		//printf("[%d] %s\t%s\t%s\n", i+1, adp->adpersons[i].name, adp->adpersons[i].phone, adp->adpersons[i].address);
	}
}
//添加联系人函数
void addPerson(addressbook* adp) {
	if (adp->size >= adp->capacity) {
		//printf("通讯录已满,添加失败！\n");
		//扩容
		adp->capacity += 100;
		//重新申请空间(realloc函数实现）
		adp->adpersons = realloc(adp->adpersons, adp->capacity * sizeof(person));

		////重新申请空间(malloc函数实现)
		//person* old = adp->adpersons; //定义一个指向旧的小的空间的指针
		////申请一个更大的空间
		//adp->adpersons = (person*)malloc(adp->adpersons, adp->capacity * sizeof(person));
		//memcpy(adp->adpersons, old, sizeof(person) * adp->size);
		//free(old);
	}
	person* p = &adp->adpersons[adp->size];
	printf("请输入新联系人姓名:");
	scanf("%s", p->name);
	printf("请输入新联系人电话：");
	scanf("%s", p->phone);
	printf("请输入新联系人地址：");
	scanf("%s", p->address);

	adp->size++;

	//保存数据到磁盘文件
	save(adp);
	printf("新增联系人成功！\n");
}
//查找联系人函数(根据姓名查找)
void findPerson(addressbook* adp) {
	assert(adp != NULL);
	printf("请输入要查找联系人的姓名：");
	char name[1024] = { 0 };
	int count = 0;
	scanf("%s", name);
	for (int i = 0; i < adp->size; i++) {
		person* p = &adp->adpersons[i];
		if (strcmp(name,p->name)==0) {
			printf("[%d] %s\t%s\t%s\n",i,p->name,p->phone,p->address);
			count++;
		}
	}
	printf("查找完毕！共显示 %d 个联系人\n", count);
}
//修改联系人函数
void modifyPerson(addressbook* adp) {
	assert(adp != NULL);
	showPerson(adp);
	printf("请输入需要修改的联系人序号：");
	int num = 0;
	scanf("%d", &num);
	if (num<0 || num>adp->size - 1) {
		printf("输入的联系人序号有误！\n");
		return;
	}
	//先取出序号为num的联系人结构体
	person* p = &adp->adpersons[num];
	char name[1024] = { 0 };
	printf("请输入修改的联系人姓名(输入* 表示不需要修改姓名）：");
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(p->name, name);
	}
	char phone[1024] = { 0 };
	printf("请输入修改的联系人电话(不修改输入*)：");
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(p->phone, phone);
	}
	char address[1024] = { 0 };
	printf("请输入修改的联系人地址(不修改输入*)：");
	scanf("%s", address);
	if (strcmp(address, "*") != 0) {
		strcpy(p->address, address);
	}

	save(adp);
	printf("修改联系人成功！\n");
}
//删除联系人函数
void deletePerson(addressbook* adp) {
	assert(adp != NULL);
	showPerson(adp);
	printf("请输入要删除联系人的序号：");
	int num = 0;
	scanf("%d", &num);
	if (num<0 || num>adp->size - 1) {
		printf("输出的序号有误！\n");
		return;
	}
	if (num == adp->size - 1) {
		adp->size--;
	}
	if (num < adp->size - 1) {
		adp->adpersons[num] = adp->adpersons[adp->size - 1];
		adp->size--;
	}

	save(adp);
	printf("删除成功！\n");
}
//清空通讯录函数
void clearAddressbook(addressbook* adp) {
	adp->size = 0;

	save(adp);
	printf("清空联系人成功！\n");
}


//创建一个通讯录变量
addressbook adp;
int main() {

	//初始化通讯录
	init(&adp);

	//加载数据
	load(&adp);

	Sleep(300);

	while (1) {
		//清屏
		system("cls");
		//显示菜单
		int select = menu();
		//功能选择
		func arr[] = {
			NULL,
			showPerson,
			addPerson,
			findPerson,
			modifyPerson,
			deletePerson,
			clearAddressbook
		};
		if (select < 0 || select >= (sizeof(arr) / sizeof(arr[0]))) {
			printf("输出错误！\n");
			continue;
		}
		if (select == 0) {
			printf("已退出通讯录，欢迎下次使用！\n");
			system("pause");
			return 0;
		}
		arr[select]((&adp));
		system("pause");
	}

	system("pause");
	return 0;
}