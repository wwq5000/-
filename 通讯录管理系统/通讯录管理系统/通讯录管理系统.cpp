#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

void show() {
	cout << "***************************" << endl;
	cout << "****** 1�������ϵ�� ******" << endl;
	cout << "****** 2����ʾ��ϵ�� ****** " << endl;
	cout << "****** 3��ɾ����ϵ�� ******" << endl;
	cout << "****** 4��������ϵ�� ******" << endl;
	cout << "****** 5���޸���ϵ�� ******" << endl;
	cout << "****** 6�������ϵ�� ******" << endl;
	cout << "****** 0���˳�ͨѶ¼ ******" << endl;
	cout << "***************************" << endl;
}


struct people {//��Ա��Ϣ
	string Name;
	int Sex;
	int Age;
	long long Phone;
	string Home;
};


struct tongxunlu {//����ͨѶ¼
	struct people c[MAX];
	int size;
};


void add(tongxunlu *abs) {//�����ϵ��
	if (abs->size == MAX) {
		cout << "��Ա���������ܼ������" << endl;
		return;
	}
	else {
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->c[abs->size].Name = name;
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl; 
		cout << "2----Ů" << endl;
		chongsex:int sex = 0;
		cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->c[abs->size].Sex = sex;

		}
		else {
			cout << "����������������롣" << endl;
				goto chongsex;
		}
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->c[abs->size].Age = age;
		cout << "�������ֻ�����" << endl;
		long long phone = 0;
		cin >> phone;
		abs->c[abs->size].Phone = phone;
		cout << "�������ͥסַ" << endl;
		string home;
		cin >> home;
		abs->c[abs->size].Home = home;
		abs->size ++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}


void show(tongxunlu *abs) {//��ʾ��ϵ��
	if (abs->size == 0) {
		cout << "����Ϊ0" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			cout << "������" << abs->c[i].Name<<'\t';
			cout << "�Ա�" << ( abs->c[i].Sex == 1 ?"��":"Ů") << '\t';
			cout << "���䣺" << abs->c[i].Age<<'\t';
			cout << "�绰���룺" << abs->c[i].Phone<<'\t';
			cout << "��ͥסַ��" << abs->c[i].Home << endl;

		}
	}
	system("pause");
	system("cls");
}

int existence(tongxunlu * abs , string name) {//����Ƿ����
	for (int i = 0; i < abs->size; i++) {
		if (abs->c[i].Name == name) {
			return i;
		}
	}
	return -1;
}
void clear(tongxunlu *abs) {//ɾ����ϵ��
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = existence(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else {
		for (int j = ret; j < abs->size; j++) {
			abs->c[j] = abs->c[j+1];//����ǰ��
		}
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void find(tongxunlu* abs) {//������ϵ��
	cout << "������������ҵ���ϵ�˵����֣�" << endl;
	string name;
	cin >> name;
	int ret = existence(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout <<"������" << abs->c[ret].Name << '\t'
			<<"���䣺" << abs->c[ret].Age << '\t'
			<<"�Ա�" << abs->c[ret].Sex << '\t'
			<<"�绰���룺" << abs->c[ret].Phone << '\t'
			<<"��ͥסַ��" << abs->c[ret].Home << endl;
	}
	system("pause");
	system("cls");
}


void modify(tongxunlu* abs) {//�޸���ϵ�˵���ֵ
	string name;
	int age;
	int esx;
	long long phone;
	string home;
	cout << "�����������޸ĵ��˵�����" << endl;
	cin >> name;
	int tep = existence(abs, name);
	if(tep == -1){
		cout << "���޴���" << endl;
	}
	else {
		cout << "�����������޸ĵ��˵����䣺" << endl;
		cin >> age;
		cout << "�����������޸ĵ��˵��Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		cin >> esx;
		cout << "�����������޸ĵ��˵ĵ绰���룺" << endl;
		cin >> phone;
		cout << "�����������޸ĵ��˵ļ�ͥסַ��" << endl;
		cin >> home;
		abs->c[tep].Name = name;
		abs->c[tep].Age = age;
		abs->c[tep].Sex = esx;
		abs->c[tep].Phone = phone;
		abs->c[tep].Home = home;
		cout << "�޸ĳɹ�"<<endl;
	}
	system("pause");
	system("cls");
}

void allclear(tongxunlu* abs) {//�����ϵ��
	k:cout << "���Ƿ�ȷʵҪ��գ�" << endl;
	cout << "1----��" << endl;
	cout << "2----��" << endl;
	int s = 0;
	cin >> s;
	if(s == 1||s == 2){
		if (s == 1) {
			abs->size = 0;
			cout << "��ֵ��ȫ����ա�" << endl;
		}
		else {
			goto y;
		}
	}
	else {
		cout << "�����������������" << endl;
		s = 0;
		goto k;
	}
	y:system("pause");
	system("cls");
}



int main(){

	tongxunlu abs;
	abs.size = 0;


	
	while (1) {
		show();
		int a = 0;
		cin >> a;
		switch (a) {
		case 1://���
			add(&abs);
			break;
		case 2://��ʾ
			show(&abs);
			break;
		case 3://ɾ��
			clear(&abs);
			break;
		case 4://����
			find(&abs);
			break;
		case 5://�޸�
			modify(&abs);
			break;
		case 6://���
			allclear(&abs);
			break;
		case 0://�˳�
			cout << "��ӭ���´�ʹ�ñ����ܡ�" << endl;
			goto b;
			break;
		default:
			break;
		}
	}
	


	b:system("pause");
	return 0;
}