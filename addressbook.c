#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<assert.h>

#define MAX 200

//ͨѶ¼����ϵͳ
//�ṹ�壺�ˣ���ϵ�˵����ԣ�
typedef struct person {
	char name[1024];  //1024=1k
	char phone[1024];
	char address[1024];
}person;
//�ṹ�壺ͨѶ¼�����ԣ�������ϵ�˸�������ϵ�����飬������
typedef struct addressbook {
	int size;           //ʵ����ϵ�˸���
	person* adpersons;  //�ĳ�ָ����ʽ��ͨ����̬�ڴ����ķ�ʽ�����г�ʼ�� 
	int capacity;       //����:��ʾ��ǰ�˽ṹ��person�Ŀռ��������
}addressbook;

//��ʼ��ͨѶ¼��������ʾ�������ڴ�ռ䣩
void init(addressbook* adp) {
	adp->size = 0;
	adp->capacity = 200; //�൱�ڳ�ʼ������ͨѶ¼�������200����ϵ��<=>MAX
	//��̬�����ڴ�ռ�
	adp->adpersons = (person*)malloc(adp->capacity * sizeof(person));

	//memset(adp->adpersons, 0, sizeof(person)*adp->capacity);//��ʼ������ͨѶ¼
}

//ͨѶ¼�˵�
int menu() {
	printf("================================================\n");
	printf("============         ͨѶ¼       ==============\n");
	printf("============  1.��ʾ��ϵ�˹���    ==============\n");
	printf("============  2.�����ϵ�˹���    ==============\n");
	printf("============  3.������ϵ�˹���    ==============\n");
	printf("============  4.�޸���ϵ�˹���    ==============\n");
	printf("============  5.ɾ����ϵ�˹���    ==============\n");
	printf("============  6.�����ϵ�˹���    ==============\n");
	printf("============  0.�˳�ͨѶ¼����    ==============\n");
	printf("================================================\n");
	int select = 0;
	printf("��������ѡ��Ĺ��ܣ�");
	scanf("%d", &select);
	return select;
}

//����һ��ʵ�ֲ�ͬ���ܵĺ���ָ��
typedef void (*func)(addressbook* adp);

//����һ�麯����ɱ��浽�ļ��Լ����ļ���������
//ʵ�ְ�ͨѶ¼���ݱ��浽�ļ���
void save(addressbook* adp) {
	//1.���ļ�
	FILE* f = fopen("D:/22.txt", "w");
	if (f == NULL) {
		perror("�ļ���ʧ��");
		return;
	}
	//2.д�루����ͨѶ¼���ݣ�
	//for (int i = 0; i < adp->size; i++) {
	//	person* p = &adp->adpersons[i];
	//	fwrite(p, sizeof(person), 1, f);
	//}
	fwrite(adp->adpersons, sizeof(person), adp->size, f);
	//3.�ر��ļ�
	fclose(f);
}
//���ļ��м������ݵ�ͨѶ¼��
void load(addressbook* adp) {
	//1.���ļ�
	FILE* f = fopen("D:/22.txt", "r");
	if (f == NULL) {
		printf("��ǰ�ļ���δ������\n");
		return;
	}
	//2.��ȡ����(ע���ȡ�����п�����Ҫ���ݣ������ʹ��ѭ������Ϊ����)
	while (1) {
		person fperson = { 0 };
		size_t len = fread(&fperson, sizeof(person), 1, f);
		if (len == 0) {
			printf("��ȡ�ɹ���\n");
			break;
		}
		//�Ѷ�ȡ��person�����е�����һ�����ӵ�ͨѶ¼�ṹ����ϵ�˵ı�����ȥ
		if (adp->size >= adp->capacity) {
			//�ڴ治������Ҫ������
			person* old = adp->adpersons;
			adp->capacity += 100;
			adp->adpersons = (person*)malloc(adp->capacity * sizeof(person));
			memcpy(adp->adpersons, old, sizeof(person) * adp->size);

			free(old);//�ͷžɿռ�
		}
		//��ֵ����
		adp->adpersons[adp->size] = fperson;
		adp->size++;
	}
	//3.�ر��ļ�
	fclose(f);
}

//��ʾ��ϵ�˺���
void showPerson(addressbook* adp) {
	assert(adp != NULL);
	if (adp->size == 0) {
		printf("��ͨѶ¼û����ϵ�ˣ�\n");
		return;
	}
	printf("������ϵ����Ϣ���£�\n");
	for (int i = 0; i < adp->size; i++) {
		person* p = &adp->adpersons[i];
		printf("[%d] %s\t%s\t%s\n", i, p->name, p->phone, p->address);
		//printf("[%d] %s\t%s\t%s\n", i+1, adp->adpersons[i].name, adp->adpersons[i].phone, adp->adpersons[i].address);
	}
}
//�����ϵ�˺���
void addPerson(addressbook* adp) {
	if (adp->size >= adp->capacity) {
		//printf("ͨѶ¼����,���ʧ�ܣ�\n");
		//����
		adp->capacity += 100;
		//��������ռ�(realloc����ʵ�֣�
		adp->adpersons = realloc(adp->adpersons, adp->capacity * sizeof(person));

		////��������ռ�(malloc����ʵ��)
		//person* old = adp->adpersons; //����һ��ָ��ɵ�С�Ŀռ��ָ��
		////����һ������Ŀռ�
		//adp->adpersons = (person*)malloc(adp->adpersons, adp->capacity * sizeof(person));
		//memcpy(adp->adpersons, old, sizeof(person) * adp->size);
		//free(old);
	}
	person* p = &adp->adpersons[adp->size];
	printf("����������ϵ������:");
	scanf("%s", p->name);
	printf("����������ϵ�˵绰��");
	scanf("%s", p->phone);
	printf("����������ϵ�˵�ַ��");
	scanf("%s", p->address);

	adp->size++;

	//�������ݵ������ļ�
	save(adp);
	printf("������ϵ�˳ɹ���\n");
}
//������ϵ�˺���(������������)
void findPerson(addressbook* adp) {
	assert(adp != NULL);
	printf("������Ҫ������ϵ�˵�������");
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
	printf("������ϣ�����ʾ %d ����ϵ��\n", count);
}
//�޸���ϵ�˺���
void modifyPerson(addressbook* adp) {
	assert(adp != NULL);
	showPerson(adp);
	printf("��������Ҫ�޸ĵ���ϵ����ţ�");
	int num = 0;
	scanf("%d", &num);
	if (num<0 || num>adp->size - 1) {
		printf("�������ϵ���������\n");
		return;
	}
	//��ȡ�����Ϊnum����ϵ�˽ṹ��
	person* p = &adp->adpersons[num];
	char name[1024] = { 0 };
	printf("�������޸ĵ���ϵ������(����* ��ʾ����Ҫ�޸���������");
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(p->name, name);
	}
	char phone[1024] = { 0 };
	printf("�������޸ĵ���ϵ�˵绰(���޸�����*)��");
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(p->phone, phone);
	}
	char address[1024] = { 0 };
	printf("�������޸ĵ���ϵ�˵�ַ(���޸�����*)��");
	scanf("%s", address);
	if (strcmp(address, "*") != 0) {
		strcpy(p->address, address);
	}

	save(adp);
	printf("�޸���ϵ�˳ɹ���\n");
}
//ɾ����ϵ�˺���
void deletePerson(addressbook* adp) {
	assert(adp != NULL);
	showPerson(adp);
	printf("������Ҫɾ����ϵ�˵���ţ�");
	int num = 0;
	scanf("%d", &num);
	if (num<0 || num>adp->size - 1) {
		printf("������������\n");
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
	printf("ɾ���ɹ���\n");
}
//���ͨѶ¼����
void clearAddressbook(addressbook* adp) {
	adp->size = 0;

	save(adp);
	printf("�����ϵ�˳ɹ���\n");
}


//����һ��ͨѶ¼����
addressbook adp;
int main() {

	//��ʼ��ͨѶ¼
	init(&adp);

	//��������
	load(&adp);

	Sleep(300);

	while (1) {
		//����
		system("cls");
		//��ʾ�˵�
		int select = menu();
		//����ѡ��
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
			printf("�������\n");
			continue;
		}
		if (select == 0) {
			printf("���˳�ͨѶ¼����ӭ�´�ʹ�ã�\n");
			system("pause");
			return 0;
		}
		arr[select]((&adp));
		system("pause");
	}

	system("pause");
	return 0;
}