///*********************************
// * [����ҽԺ����ϵͳ���ŶӲ���].CPP.B.0.M
// *********************************/
//#define _CRT_SECURE_NO_WARNINGS
//#include <sstream>
//#include <iostream>
//#include <ctime>
//#include <time.h>
//#include <windows.h>
//
//using namespace std;
//typedef int QElemType;
//const int k = 100;
//char stick[k];
//int n;
//
//class Basic
//{
//public:
//    string data;
//    char Rsequence; // �Һ�����
//    char grade;     // ҽ���ȼ�
//    Basic* next;
//};
//
//class Queue
//{
//public:
//    Basic* front, * rear;     // ����ͷβָ��
//    void Iniqueue(Queue& s); // ��ʼ��һ����ʼ�����У�����ÿ�ν��������ǰ������
//    void Enqueue0(Queue& s, char b);
//    void Enqueue(Queue& s, char b); // ���˹Һ�
//    void Enqueue(Queue& s, string a, char b);
//    void Enqueue1(Queue& s, string a, char b);
//    void Enqueue2(Queue& s, string a, char b);
//    void DLqueue(Queue& s);    // ������
//    string Gethead1(Queue& s); // ����data
//    char Gethead2(Queue& s);   // ����Rsequence
//    char Gethead3(Queue& s);   // ����grade
//    string Gethead4(Queue& s);
//    int Empty(Queue& s);  // �п�
//    void Print(Queue& s); // ���
//    friend class Custom;
//};
//
//class Custom // ������
//{
//public:
//    void ProductStick(int n);
//    void WaitList(Queue& custom1, int n);
//    void WaitList1(Queue& custom2, Queue& Q, Queue& Q3, int n);
//};
//
//class Doctor // ҽ����
//{
//public:
//    void PDoctor(Queue& doctoren);
//    void ServeStick(Queue& doctoren, Queue& customque);
//    void ServestickFinish(Queue& doctoren, Queue& customque);
//    char grade1; // ��������ҽ���ȼ� ����������
//};
//
//class Total
//{
//public:
//    void Strategy1(Queue& customque, Queue& doctorque, Custom& customren, Doctor& doctorman, Queue& checkstick);           // һ������ҽ��ģʽ
//    void Strategy2(Queue& customque, Queue& Q, Queue& doctorque, Custom& customren, Doctor& doctorman, Queue& checkstick); // ��������ҽ��ģʽ
//    void DoctorCheck(Queue& checkstick, Queue& customque);
//    void DoctorCheck1(Queue& checkstick, Queue& cQ2);
//    int Counttime();
//};
//void Queue::Iniqueue(Queue& s) // ��ʼ��һ����ʼ�����У�����ÿ�ν��������ǰ������***
//{
//    Basic* p;
//    p = new Basic;
//    p->next = NULL;
//    s.front = p;
//    s.rear = p;
//}
//
//void Queue::Enqueue(Queue& s, char b) // ��ҽ����Ϣ�����***
//{
//    Basic* p;
//    string num;
//    string num1;
//    p = new Basic;
//    if (b == 'A' || b == 'S')
//        p->grade = b;
//    else {
//        cout << "�������!��������(SΪר�Һ�  AΪ��ͨ��)�����δ��󲻼����������" << endl;
//    }
//    p->next = s.rear->next;
//    s.rear->next = p;
//    s.rear = p;
//}
//void Queue::Enqueue0(Queue& s, char b) { // ���˹Һ�***
//    Basic* p;
//    string num;
//    string num1;
//    p = new Basic;
//    cout << "�����벡�˹Һ����:" << endl;
//    cin >> num;
//    p->data = num;
//    p->Rsequence = b; // ͨ��productstick������Rsequence�����������a����b��
//    cout << "����Ҫ����ͨ�Ż���ר�Һ�:a(��ʾ��ͨ��) b(��ʾר�Һ�)" << endl;
//    cin >> p->grade;
//    p->next = s.rear->next;
//    s.rear->next = p;
//    s.rear = p;
//}
//
//void Queue::Enqueue(Queue& s, string a, char b) //***
//{
//    Basic* p;
//    string num;
//    string num1;
//    p = new Basic;
//    if (b == 'C') // �ж��ǵ�һ�λ��ǵڶ�����ϣ�cΪ�ڶ��Σ�aΪ��һ�Σ�9
//    {
//        p->data = a;
//        p->Rsequence = b;
//        p->next = s.rear->next;
//        s.rear->next = p;
//        s.rear = p;
//    }
//    else if (b == 'A') {
//        p->data = a;
//        p->Rsequence = b;
//        p->next = s.front->next;
//        s.front->next = p;
//    }
//}
//
//void Queue::Enqueue1(Queue& s, string a, char b) {
//    Basic* p;
//    string num;
//    string num1;
//    p = new Basic;
//    p->data = a;
//    p->Rsequence = b;
//    p->next = s.rear->next;
//    s.rear->next = p;
//    s.rear = p;
//}
//void Queue::Enqueue2(Queue& s, string a, char b) // ʹ�����Ĳ��˻ص���ͷ
//{
//    Basic* p;
//    string num;
//    string num1;
//    p = new Basic;
//    p->data = a;
//    p->Rsequence = b;
//    p->next = s.front->next;
//    s.front->next = p;
//    s.rear = p;
//}
//string Queue::Gethead1(Queue& s) {
//    if (s.front == s.rear)
//        return NULL;
//    else
//        return s.front->next->data;
//}
//
//string Queue::Gethead4(Queue& s) {
//    if (s.front == s.rear)
//        return NULL;
//    else
//        return s.front->next->data;
//}
//char Queue::Gethead2(Queue& s) //***
//{
//    if (s.front == s.rear)
//        return NULL;
//    else
//        return s.front->next->Rsequence; // ָ��Һ�����Rsequence �õ�A����B���Ͳ���
//}
//
//char Queue::Gethead3(Queue& s) {
//    if (s.front == s.rear)
//        return NULL;
//    else
//        return s.front->next->grade;
//}
//
//void Queue::DLqueue(Queue& s) //  ɾ��������Ԫ��
//{
//    Basic* p;
//    p = s.front->next;
//    if (p->next == NULL) {
//        s.front->next = NULL;
//        s.front = s.rear;
//    }
//    else
//        s.front->next = p->next;
//    delete p;
//}
//
//int Queue::Empty(Queue& s) // �жϱ��***
//{
//    if (s.front == s.rear)
//        return 1;
//    else
//        return 0;
//}
//
//void Custom::ProductStick(int n) // ����һ�������stick[i]=A����B***
//{
//    char stickclass;
//    int x;
//    srand((unsigned int)time(NULL)); // time��NULL���ǲ���һ����1900��1��1�յ����ڵ�ʱ��������srand(time(NULL))����ͨ������ʱ��Ĳ�ͬ������ͬ�����
//    for (int i = 1; i <= n; i++) {
//        x = int(rand()) % 2;
//        if (x)
//            stickclass = 'A';
//        else
//            stickclass = 'B';
//        stick[i] = stickclass;
//    }
//}
//
//void Custom::WaitList(Queue& custom1, int n) // һ������ģʽ�Ĵ���������***
//{
//    custom1.Iniqueue(custom1); // ���ô��������� ����һ��
//    for (int i = 1; i <= n; i++)
//        custom1.Enqueue0(custom1, stick[i]); // �������stick[]
//}
//
//void Custom::WaitList1(Queue& Q1, Queue& Q2, Queue& Q3, int n) // ��������ģʽ�Ĵ���������***
//{
//    Q1.Iniqueue(Q1); // ��ʼ��Q1������������
//    Q2.Iniqueue(Q2); // ��ʼ��Q2������������
//    Q3.Iniqueue(Q3);
//    for (int i = 1; i <= n; i++) {
//        if (i <= 3)
//            Q1.Enqueue0(Q1, stick[i]); // ��������಻����3����
//        else
//            Q2.Enqueue0(Q2, stick[i]); // ����ķ��������
//    }
//}
//
//void Doctor::PDoctor(Queue& doctoren) // �Ӽ��̽���ҽ����Ϣ***
//{
//    char x;
//    int n;
//    char m;
//    doctoren.Iniqueue(doctoren); // ��ʼ����
//    cout << "��������ͨҽ����ר������:����n��,һ������ֻ������һ��ר�ң�ʣ��n-1��Ϊ��ͨҽ����" << endl;
//    cin >> n;
//    m = n;
//    for (int i = 1; i <= n; i++) {
//        cout << "������ A ��ʾ��ͨҽ��, S ��ʾר��" << endl;
//        cin >> x;
//        grade1 = x;
//        if (grade1 != 'S' && grade1 != 'A') {
//            n++;
//        }                                   // ������ٸ���������
//        doctoren.Enqueue(doctoren, grade1); // �������������
//    }
//}
//
//void Doctor::ServeStick(Queue& doctoren, Queue& customque) // �������***
//{
//    Queue storage;
//    char ch;
//    if (doctoren.Empty(doctoren))
//        cout << "û�п���ҽ��,��ȴ�!" << endl;
//    else {
//        string x2 = customque.Gethead1(customque);
//        ch = doctoren.Gethead3(doctoren);
//        doctoren.DLqueue(doctoren);
//        storage.Iniqueue(storage);
//        storage.Enqueue(storage, ch);
//        cout << x2 << "��"
//            << "�������֮��:�����ĵȴ�!:" << endl;
//    }
//}
//
//void Doctor::ServestickFinish(Queue& doctoren, Queue& customque) // ������***
//{
//    string x;
//    x = customque.Gethead1(customque);
//    if (customque.Gethead2(customque) == 'A' || customque.Gethead2(customque) == 'C') {
//        cout << x << "��"
//            << "����������"
//            << "���ò���ΪA���Ͳ�" << endl;
//    }
//    if (customque.Gethead2(customque) == 'B') {
//        cout << x << "��"
//            << "����������"
//            << "���ò���ΪB���Ͳ�����ȥ����������Ϻ󷵻أ�" << endl;
//        n = 1;
//    }
//    if (customque.Gethead2(customque) == 'D') {
//        cout << x << "��"
//            << "����������" << endl;
//    }
//    customque.DLqueue(customque);
//    doctoren.Enqueue(doctoren, grade1);
//}
//
//int Total::Counttime() // ���þ���ʱ�� ***
//{
//    int x;
//    time_t now_time;
//    now_time = time(NULL);
//    struct tm now = *localtime(&now_time);
//    x = now.tm_sec;
//    return x;
//}
//
//void Total::Strategy1(Queue& customque, Queue& doctorque, Custom& customren, Doctor& doctorman, Queue& checkstick) // һ������ҽ��ģʽ***
//{
//    string x;
//    static int count1 = 0;
//    int time1, time2;
//    if (!customque.Empty(customque)) {
//        x = customque.Gethead1(customque);
//        time1 = 0;
//        if (customque.Gethead2(customque) == 'A' || customque.Gethead2(customque) == 'C') // ����Ҫ����A�Ͳ���(productstick ������stick���������a��b����a����Ҫ��졢b����Ҫ���)
//        {
//            doctorman.ServeStick(doctorque, customque);
//            doctorman.ServestickFinish(doctorque, customque);
//            time2 = Counttime();
//            cout << "��ϻ���" << time2 - time1 << "����   " << endl;
//            ;
//        }
//        else // ��Ҫ����B���Ͳ���
//        {
//            doctorman.ServeStick(doctorque, customque);
//            checkstick.Enqueue(checkstick, x, 'C');
//            doctorman.ServestickFinish(doctorque, customque);
//            time2 = Counttime();
//            cout << "��ϻ���" << time2 - time1 << "����" << endl;
//        }
//    }
//    else {
//        cout << "������û�в��˵ȴ�!" << endl;
//    }
//}
//
//int stringToInt(const string& s) // string��תint�ͺ���
//{
//    stringstream ss;
//    int result;
//    ss << s;
//    ss >> result;
//    return result;
//}
//
//void Total::Strategy2(Queue& Q1, Queue& Q2, Queue& doctorque, Custom& customren1, Doctor& doctorman, Queue& checkstick) // ��������ҽ��ģʽ
//{
//    string x, num;
//    char ge;
//    static int count2 = 0;
//    int time1, time2;
//    if (!Q1.Empty(Q1)) {
//        x = Q1.Gethead1(Q1);
//        time1 = 0;
//        if (Q1.Gethead2(Q1) == 'A' || Q1.Gethead2(Q1) == 'C') // ����Ҫ����A�Ͳ���
//        {
//            doctorman.ServeStick(doctorque, Q1);
//            doctorman.ServestickFinish(doctorque, Q1);
//            time2 = Counttime();
//            cout << "��ϻ���" << time2 - time1 << "����  " << endl;
//        }
//        else // ��Ҫ����B�Ͳ���
//        {
//            doctorman.ServeStick(doctorque, Q1);
//            checkstick.Enqueue(checkstick, x, 'C');
//            doctorman.ServestickFinish(doctorque, Q1);
//            time2 = Counttime();
//            cout << "��ϻ���" << time2 - time1 << "����" << endl;
//        }
//    }
//    else if (!Q2.Empty(Q2)) {
//        cout << "������(Q1)û�в��˵ȴ�! �������(Q2)�������:" << endl;
//        int j;
//        num = Q2.Gethead4(Q2);
//        ge = Q2.Gethead2(Q2);
//        j = stringToInt(num);
//        Q1.Enqueue1(Q1, num, ge);
//        Q2.DLqueue(Q2);
//    }
//    else {
//        cout << "������(Q1)�������(Q2)��û�в��˵ȴ�!" << endl;
//    }
//}
//
//void Total::DoctorCheck(Queue& checkstick, Queue& customque) // һ������ģʽ���ģʽ***
//{
//    string x;
//    if (!checkstick.Empty(checkstick) && n == 1) {
//        x = checkstick.Gethead1(checkstick);
//         //��鲡���Ƿ��Ѿ�����������
//        if (customque.Gethead2(customque) != 'D') {
//            cout << x << "��"
//                << "���֮��" << endl;
//            customque.Enqueue2(customque, x, 'D'); // ��Rsequence��ΪD ʹ�����������ϵ���������֮ǰ�ĵ�һ�β�һ��
//            Sleep(1000);
//            cout << x << "��"
//                << "������"
//                << "���뷵�ؾ����Ҽ�������!" << endl;
//            Sleep(1000);
//        }
//        checkstick.DLqueue(checkstick); // Remove patient from the checkstick queue
//        n = 0;
//    }
//    else
//        cout << "û�в���Ҫ���м��:" << endl;
//}
//
//void Total::DoctorCheck1(Queue& checkstick, Queue& Q2) // ��������ģʽ�����ģʽ***
//{
//    string x;
//    if (!checkstick.Empty(checkstick)) {
//        x = checkstick.Gethead1(checkstick);
//         //��鲡���Ƿ��Ѿ�����������
//        if (Q2.Gethead2(Q2) != 'D') {
//            cout << x << "��"
//                << "���֮��" << endl;
//            Q2.Enqueue2(Q2, x, 'D');
//            Sleep(1000);
//            cout << x << "��"
//                << "������"
//                << "���뷵�ؾ����Ҽ�������!" << endl;
//            Sleep(1000);
//        }
//        checkstick.DLqueue(checkstick); // Remove patient from the checkstick queue
//    }
//    else
//        cout << "û�в���Ҫ���м��:" << endl;
//}
//int main() // ������
//{
//    cout << "\t\t**************************" << endl;
//    cout << "\t\t**\t\t\t**" << endl;
//    cout << "\t\t**   ҽԺ����ϵͳ�Ŷ�   **" << endl;
//    cout << "\t\t**\t\t\t**" << endl;
//    cout << "\t\t**************************\n"
//        << endl;
//    cout << "\t\t **������س��Խ���ϵͳ**";
//    Queue Q1, Q2, Q3, customque, doctorque, checkstick, checkstick1;
//    Custom customren, customren1;
//    Doctor doctorman;
//    Total k;
//    int n;
//    int m = 1;
//    checkstick.Iniqueue(checkstick);
//    checkstick1.Iniqueue(checkstick1);
//    getchar();
//    system("cls");
//    while (m != 8) {
//        cout << " \t ******|   ����Ϊ�����б��������Ӧ��������ʹ�ù���     " << endl;
//        cout << " \t ******|1. ҽ����Ϣ����            " << endl;
//        cout << " \t ******|2. һ������ģʽ�Ĳ��˹Һ�  " << endl;
//        cout << " \t ******|3. ��������ģʽ�Ĳ��˹Һ�  " << endl;
//        cout << " \t ******|4. һ������ģʽģ�⣬ÿ������һ������        " << endl;
//        cout << " \t ******|5. ��������ģʽģ�⣬ÿ������һ������        " << endl;
//        cout << " \t ******|6. һ������ģʽ ���ϵͳ" << endl;
//        cout << " \t ******|7. ��������ģʽ ���ϵͳ" << endl;
//        cout << " \t ******|8. �˳�ϵͳ " << endl;
//        cin >> m;
//        switch (m) {
//        case 1:
//            cout << "ҽ����Ϣ����:" << endl;
//            doctorman.PDoctor(doctorque);
//            Sleep(1000);
//            break;
//        case 2:
//            cout << "������Ҫ����������:" << endl;
//            cin >> n;
//            customren.ProductStick(n);
//            cout << "������ӹҺ�" << endl;
//            customren.WaitList(customque, n);
//            Sleep(1000);
//            break;
//        case 3:
//            cout << "������Ҫ����������:" << endl;
//            cin >> n;
//            customren.ProductStick(n);
//            cout << "������ӹҺ�" << endl;
//            customren1.WaitList1(Q1, Q2, Q3, n);
//            Sleep(1000);
//
//            break;
//        case 4:
//            k.Strategy1(customque, doctorque, customren, doctorman, checkstick);
//            Sleep(1000);
//            break;
//        case 5:
//            k.Strategy2(Q1, Q2, doctorque, customren1, doctorman, checkstick1);
//            Sleep(1000);
//
//            break;
//        case 6:
//            k.DoctorCheck(checkstick, customque);
//            Sleep(1000);
//            break;
//        case 7:
//            k.DoctorCheck1(checkstick1, Q2);
//            Sleep(1000);
//            break;
//        case 8:
//            cout << "ллʹ�ã�" << endl;
//        }
//    }
//}