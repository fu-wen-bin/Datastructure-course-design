#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include <windows.h>

#define k 100
char sick[k]; //������������

typedef struct Doctor {
	char Ddata[50];
	char DRsequence;
	char Dgrade;     // ҽ���ȼ�
	struct Doctor* next;
} Doctor, * DoctorList;

typedef struct DQueue { //ҽ������
	DoctorList front, rear;
	int size;
}DQueue;

typedef struct Patient {
	char Ptype; //������������
	char Pdata[50]; //���˹Һ�����
	char Pgrade; //���˹Һŵ�ҽ���ȼ�
	char Finalstatus; //������״̬
	struct Patient* next;
} Patient, * PatientList;

typedef struct PQueue { //���߶���
	PatientList front, rear;
	int size;
}PQueue;


void Iniqueue(PQueue* patientque) { //��ʼ�����˶���
	patientque->front = patientque->rear = NULL;
}

void Enqueue0(PQueue* patientque, char Ptype, int i) { //���˶��н���
	PatientList p = (PatientList)malloc(sizeof(Patient));
	char num[50];
	printf("\t   �����%dλ���˵ĹҺ����:", i);
	scanf("%s", num);
	strcpy(p->Pdata, num);
	p->Finalstatus = p->Ptype = Ptype;
	printf("   Ҫ����ͨ�Ż���ר�Һ� N(��ͨ��) S(ר�Һ�):");
	scanf(" %c", &p->Pgrade);
	p->next = NULL; //��Ԫ����ӡ���βָ��ָ���½ڵ�
	if (patientque->front == NULL) {
		patientque->front = p;
	}
	else
		patientque->rear->next = p;
	patientque->rear = p;
}

void Enqueue1(PQueue* Q1, PQueue* Q2) {

	PatientList p = (PatientList)malloc(sizeof(Patient));
	p->Finalstatus = Q2->front->Finalstatus;
	strcpy(p->Pdata, Q2->front->Pdata);
	p->Pgrade = Q2->front->Pgrade;
	p->Ptype = Q2->front->Ptype;
	if (Q1->front == NULL) {
		Q1->front = p;
	}
	else
		Q1->rear->next = p;
	Q1->rear = p;
}

char GetPatientHead_type(PQueue* patientque) {
	if (patientque->front == NULL)
		return NULL;
	else
		return patientque->front->Ptype;
}

char* GetPatientHead_data(PQueue* patientque) {
	if (patientque->front == NULL)
		return NULL;
	else
		return patientque->front->Pdata;
}

char GetPatientHead_doctype(PQueue* patientque) {
	if (patientque->front == NULL)
		return NULL;
	else
		return patientque->front->Pgrade;
}

void Enqueue2(PQueue* checksick, PQueue* patientque, char a[], char type) { //����겡�˻ص���ͷ
	PatientList p = (PatientList)malloc(sizeof(Patient));
	strcpy(p->Pdata, a);
	p->Ptype = GetPatientHead_type(checksick);
	p->Pgrade = GetPatientHead_doctype(checksick);
	p->Finalstatus = type;
	p->next = patientque->front;
	patientque->front = p;
}

void DLqueue(PQueue* patientque) {
	if (patientque->front == NULL)
		return 0;
	PatientList p = patientque->front;
	patientque->front = p->next;
	free(p);
}

int PEmpty(PQueue* patientque) {
	if (patientque->front == NULL)
		return 1;
	else
		return 0;
}

int DEmpty(DQueue* patientque) { //�ж�ҽ�������Ƿ�Ϊ��
	if (patientque->front == patientque->rear)
		return 1;
	else
		return 0;
}

int DType_Empty(DoctorList doctor, char doctype) { //�ж�Ŀ�����͵�ҽ�������Ƿ�Ϊ��
	if (doctor == NULL)
		return NULL;
	if (doctor->Dgrade == doctype)
		return 1;
	else
		DType_Empty(doctor->next, doctype);
}

void ProductSick(PQueue* patientque) { //������������
	char sickclass;
	int x;
	for (int i = 1; i <= (patientque->size); i++) {
		x = rand() % 2;
		if (x)
			sickclass = 'A';
		else
			sickclass = 'B';
		sick[i] = sickclass;
	}
}

void WaitList(PQueue* patientque) { //����һ���������ͺ͹ҺŶ�Ӧ
	Iniqueue(patientque);
	for (int i = 1; i <= (patientque->size); i++)
		Enqueue0(patientque, sick[i], i);
}

void WaitList1(PQueue* Q1, PQueue* Q2, PQueue* patientque) { //���Զ����������ͺ͹ҺŶ�Ӧ
	for (int i = 1; i <= (patientque->size); i++) {
		if (i <= 3)
			Enqueue0(Q1, sick[i], i);
		else
			Enqueue0(Q2, sick[i], i);
	}
}

void Inidocqueue(DQueue* doctorque) { //��ʼ��ҽ������
	doctorque->front = doctorque->rear = NULL;
}

void Enqueue(DQueue* doctorque) { //ҽ�����н���
	char Doctype;
	int count = 0;
	int n = doctorque->size;
	for (int i = 1; i <= n; i++) {
		DoctorList p = (DoctorList)malloc(sizeof(Doctor));
		if (p == NULL) {
			printf("�ڴ�ռ����ʧ��");
			exit(1);
		}
		printf("������ N ��ʾ��ͨҽ����S ��ʾר��:");
		scanf(" %c", &Doctype);
		if (Doctype != 'S' && Doctype != 'N') {
			printf("�Ƿ����룬��������ȷ��ѡ��");
			n++;
		}
		if (Doctype == 'S') {
			count++;
			if (count > 1) {
				n++;
				printf("ֻ����һ��ר�ң����������룺\n");
			}
			else {
				p->Dgrade = Doctype; //��Ԫ��ѹ����С�����βָ��ָ���½ڵ�
				p->next = NULL;
				if (doctorque->front == NULL) {
					doctorque->front = p;
				}
				else
					doctorque->rear->next = p;
				doctorque->rear = p;
			}
		}
		else if (Doctype == 'N') {
			p->Dgrade = Doctype; //��Ԫ��ѹ����С�����βָ��ָ���½ڵ�
			p->next = NULL;
			if (doctorque->front == NULL) {
				doctorque->front = p;
			}
			else
				doctorque->rear->next = p;
			doctorque->rear = p;
		}
	}
	printf("\n");
}

void PDoctor(DQueue* doctorque) {
	Inidocqueue(doctorque);
	Enqueue(doctorque);
}

int ServeSick(DoctorList doctor, PQueue* patientque, char docgrade) {
	if (!DType_Empty(doctor, docgrade)) {
		printf("\t******************************\n");
		printf("û��Ŀ������ҽ��,�����¹Һ�ѡ��ҽ�������³�ʼ��ҽ��!\n\n");
		return 0;
	}
	else {
		char x2[50];
		strcpy(x2, GetPatientHead_data(patientque));
		printf("%s���������֮��:�����ĵȴ�!:\n", x2);
	}

}

void EnqueuCheck(PQueue* checksick, PQueue* patientque) {
	PatientList p = (PatientList)malloc(sizeof(Patient));
	p->Ptype = GetPatientHead_type(patientque);
	strcpy(p->Pdata, GetPatientHead_data(patientque));
	p->Pgrade = GetPatientHead_doctype(patientque);
	p->next = NULL;//��Ԫ��ѹ����С�����βָ��ָ���½ڵ�
	if (checksick->front == NULL) {
		checksick->front = p;
	}
	else
		checksick->rear->next = p;
	checksick->rear = p;
}

void ServesickFinish(PQueue* checksick, PQueue* patientque) {
	char x[50];
	strcpy(x, GetPatientHead_data(patientque));
	if (patientque->front->Finalstatus == 'A') {
		printf("%s�Ų��������ɣ��ò���ΪA���Ͳ�\n", x);
		DLqueue(patientque);
	}
	else if (patientque->front->Finalstatus == 'B') {
		printf("%s�Ų��������ɣ��ò���ΪB���Ͳ�����ȥ����������Ϻ󷵻�\n", x);
		EnqueuCheck(checksick, patientque);
		DLqueue(patientque);
	}
	else if (patientque->front->Finalstatus == 'D') {
		printf("%s�Ų���������\n", x);
		DLqueue(patientque);
	}
}

int Counttime() { //����ȴ�ʱ��
	int x = 0;
	time_t now_time;
	now_time = time(NULL);
	struct tm* now = localtime(&now_time);
	x = now->tm_sec;
	return x;
}

void Strategy1(PQueue* patientque, DQueue* doctorque, PQueue* checksick, int* menuchoice) {
	char x[50];
	int begintime, endtime;
	PatientList Patient = patientque->front;
	DoctorList Doctor = doctorque->front;
	if (!PEmpty(patientque)) {
		strcpy(x, GetPatientHead_data(patientque));
		begintime = 0;
		if (GetPatientHead_type(patientque) == 'A') {
			if (!ServeSick(Doctor, patientque, Patient->Pgrade)) {
				return *menuchoice = 1;
			}
			ServesickFinish(checksick, patientque);
			endtime = Counttime();
			printf("��ϻ���%d����\n", endtime - begintime);
		}
		else {
			if (!ServeSick(Doctor, patientque, Patient->Pgrade)) {
				return *menuchoice = 1;
			}
			ServesickFinish(checksick, patientque);
			endtime = Counttime();
			printf("��ϻ���%d����\n", endtime - begintime);
		}
	}
	else {
		printf("������û�в��˵ȴ�!\n");
	}
}

void Strategy2(PQueue* Q1, PQueue* Q2, DQueue* doctorque, PQueue* checksick, int* menuchoice) {
	char x[50];
	int begintime, endtime;
	PatientList Patient = Q1->front;
	DoctorList Doctor = doctorque->front;
	if (!PEmpty(Q1)) {
		strcpy(x, GetPatientHead_data(Q1));
		begintime = 0;
		if (GetPatientHead_type(Q1) == 'A') {
			if (!ServeSick(Doctor, Q1, Patient->Pgrade)) {
				return *menuchoice = 1;
			}
			ServesickFinish(checksick, Q1);
			endtime = Counttime();
			printf("��ϻ���%d����\n", endtime - begintime);
		}
		else {
			if (!ServeSick(Doctor, Q1, Patient->Pgrade)) {
				return *menuchoice = 1;
			}
			ServesickFinish(checksick, Q1);
			endtime = Counttime();
			printf("��ϻ���%d����\n", endtime - begintime);
		}
	}
	else if (!PEmpty(Q2)) {
		printf("������(Q1)û�в��˵ȴ�! �������(Q2)�������:\n");
		for (int i = 1; i <= 3; i++) {
			if (Q2->front != NULL) {
				Enqueue1(Q1, Q2);
				DLqueue(Q2);
			}
			else break;
		}
		Sleep(300);
		printf("������(Q2)�����ѽ��������(Q1)������ϵͳ�м���ѡ����\n");
	}
	else if (!PEmpty(Q2) && !PEmpty(Q1)) {
		printf("������(Q1)�������(Q2)��û�в��˵ȴ�!\n");
	}
}

void DoctorCheck(PQueue* checksick, PQueue* patientque) {
	char x[50];
	if (!PEmpty(checksick)) {
		strcpy(x, GetPatientHead_data(checksick));
		if (GetPatientHead_type(checksick) != 'D') {
			printf("%s�����ڼ����\n", x);
			Enqueue2(checksick, patientque, x, 'D');
			Sleep(300);
			printf("%s�ż����ɣ��뷵�ؾ����Ҽ�������!\n", x);
			Sleep(300);
		}
		DLqueue(checksick);
	}
	else {
		printf("û�в���Ҫ���м��:\n");
	}
}

int main() {
	srand((unsigned int)time(NULL));
	PQueue Q1, Q2, patientque, checksick, checksick1;
	DQueue doctorque;
	int menuchoice = 1;
	Iniqueue(&Q1); Iniqueue(&checksick1);
	Iniqueue(&Q2); Iniqueue(&checksick);
	Iniqueue(&patientque); Inidocqueue(&doctorque);

	while (menuchoice != 8) {
		printf("=================================================\n");
		printf("=           ��ӭ����ҽԺ�����Ŷ�ϵͳ            =\n");
		printf("=-----------------------------------------------=\n");
		printf("=       �����һ������ʵ�����еķ��﹦��        =\n");
		printf("=         1. ����ҽ�����е���Ϣ����             =\n");
		printf("=         2. һ������ģʽ�Ĳ��˹Һ�             =\n");
		printf("=         3. ��������ģʽ�Ĳ��˹Һ�             =\n");
		printf("=         4. һ������ģ�⣬ÿ������һ������     =\n");
		printf("=         5. ��������ģ�⣬ÿ������һ������     =\n");
		printf("=         6. һ���������ϵͳ                   =\n");
		printf("=         7. �����������ϵͳ                   =\n");
		printf("=         8. �Һ��˳�ҽԺ�����Ŷ�ϵͳ           =\n");
		printf("=-----------------------------------------------=\n");
		printf("=           ף�������տ�����������죡          =\n");
		printf("=================================================\n");
		printf("        �밴����������������ȷ��ѡ��");
		scanf("%d", &menuchoice);
		switch (menuchoice) {
		case 1:
			printf("\n\t*******************************");
			printf("\n\t\tҽ����Ϣ����:\n");
			printf("��������ͨҽ����ר��������:��ֻ����һ��ר�ң�ʣ��Ϊ��ͨҽ����\n");
			scanf("%d", &(doctorque.size));
			PDoctor(&doctorque);
			Sleep(200);
			break;
		case 2:
			printf("\n\t*******************************");
			printf("\n\t    һ������ģʽ�Ĳ��˹Һ�\n");
			printf("\t*******************************");
			printf("\n\t   ������ģ������Ĳ�����:");
			scanf("%d", &(patientque.size));
			ProductSick(&patientque);
			printf("\n\t   |      ���˹Һ����     |\n");
			printf("\t   *************************     \n");
			WaitList(&patientque);
			Sleep(300);
			break;
		case 3:
			printf("\n\t*******************************");
			printf("\n\t    ��������ģʽ�Ĳ��˹Һ�\n");
			printf("\t*******************************");
			printf("\n\t   ������ģ������Ĳ�����:");
			scanf("%d", &(patientque.size));
			ProductSick(&patientque);
			printf("\n\t   |      ���˹Һ����     |\n");
			printf("\t   *************************     \n");
			WaitList1(&Q1, &Q2, &patientque);
			Sleep(300);
			break;
		case 4:
			Strategy1(&patientque, &doctorque, &checksick, &menuchoice);
			Sleep(300);
			break;
		case 5:
			Strategy2(&Q1, &Q2, &doctorque, &checksick1, &menuchoice);
			Sleep(300);
			break;
		case 6:
			DoctorCheck(&checksick, &patientque);
			Sleep(300);
			break;
		case 7:
			DoctorCheck(&checksick1, &Q1);
			Sleep(300);
			break;
		case 8:
			printf("ллʹ�ã�\n");
			break;
		}
	}
}


