#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

void show() {
	cout << "***************************" << endl;
	cout << "****** 1、添加联系人 ******" << endl;
	cout << "****** 2、显示联系人 ****** " << endl;
	cout << "****** 3、删除联系人 ******" << endl;
	cout << "****** 4、查找联系人 ******" << endl;
	cout << "****** 5、修改联系人 ******" << endl;
	cout << "****** 6、清空联系人 ******" << endl;
	cout << "****** 0、退出通讯录 ******" << endl;
	cout << "***************************" << endl;
}


struct people {//人员信息
	string Name;
	int Sex;
	int Age;
	long long Phone;
	string Home;
};


struct tongxunlu {//制造通讯录
	struct people c[MAX];
	int size;
};


void add(tongxunlu *abs) {//添加联系人
	if (abs->size == MAX) {
		cout << "人员已满，不能继续添加" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->c[abs->size].Name = name;
		cout << "请输入性别" << endl;
		cout << "1----男" << endl; 
		cout << "2----女" << endl;
		chongsex:int sex = 0;
		cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->c[abs->size].Sex = sex;

		}
		else {
			cout << "输入错误，请重新输入。" << endl;
				goto chongsex;
		}
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->c[abs->size].Age = age;
		cout << "请输入手机号码" << endl;
		long long phone = 0;
		cin >> phone;
		abs->c[abs->size].Phone = phone;
		cout << "请输入家庭住址" << endl;
		string home;
		cin >> home;
		abs->c[abs->size].Home = home;
		abs->size ++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}


void show(tongxunlu *abs) {//显示联系人
	if (abs->size == 0) {
		cout << "人数为0" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			cout << "姓名：" << abs->c[i].Name<<'\t';
			cout << "性别：" << ( abs->c[i].Sex == 1 ?"男":"女") << '\t';
			cout << "年龄：" << abs->c[i].Age<<'\t';
			cout << "电话号码：" << abs->c[i].Phone<<'\t';
			cout << "家庭住址：" << abs->c[i].Home << endl;

		}
	}
	system("pause");
	system("cls");
}

int existence(tongxunlu * abs , string name) {//检测是否存在
	for (int i = 0; i < abs->size; i++) {
		if (abs->c[i].Name == name) {
			return i;
		}
	}
	return -1;
}
void clear(tongxunlu *abs) {//删除联系人
	cout << "请输入你要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = existence(abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		for (int j = ret; j < abs->size; j++) {
			abs->c[j] = abs->c[j+1];//数据前移
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

void find(tongxunlu* abs) {//查找联系人
	cout << "请输入你想查找的联系人的名字：" << endl;
	string name;
	cin >> name;
	int ret = existence(abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout <<"姓名：" << abs->c[ret].Name << '\t'
			<<"年龄：" << abs->c[ret].Age << '\t'
			<<"性别：" << abs->c[ret].Sex << '\t'
			<<"电话号码：" << abs->c[ret].Phone << '\t'
			<<"家庭住址：" << abs->c[ret].Home << endl;
	}
	system("pause");
	system("cls");
}


void modify(tongxunlu* abs) {//修改联系人的数值
	string name;
	int age;
	int esx;
	long long phone;
	string home;
	cout << "请输入你想修改的人的名字" << endl;
	cin >> name;
	int tep = existence(abs, name);
	if(tep == -1){
		cout << "查无此人" << endl;
	}
	else {
		cout << "请输入你想修改的人的年龄：" << endl;
		cin >> age;
		cout << "请输入你想修改的人的性别：" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		cin >> esx;
		cout << "请输入你想修改的人的电话号码：" << endl;
		cin >> phone;
		cout << "请输入你想修改的人的家庭住址：" << endl;
		cin >> home;
		abs->c[tep].Name = name;
		abs->c[tep].Age = age;
		abs->c[tep].Sex = esx;
		abs->c[tep].Phone = phone;
		abs->c[tep].Home = home;
		cout << "修改成功"<<endl;
	}
	system("pause");
	system("cls");
}

void allclear(tongxunlu* abs) {//清空联系人
	k:cout << "你是否确实要清空？" << endl;
	cout << "1----是" << endl;
	cout << "2----否" << endl;
	int s = 0;
	cin >> s;
	if(s == 1||s == 2){
		if (s == 1) {
			abs->size = 0;
			cout << "数值已全部清空。" << endl;
		}
		else {
			goto y;
		}
	}
	else {
		cout << "输入错误，请重新输入" << endl;
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
		case 1://添加
			add(&abs);
			break;
		case 2://显示
			show(&abs);
			break;
		case 3://删除
			clear(&abs);
			break;
		case 4://查找
			find(&abs);
			break;
		case 5://修改
			modify(&abs);
			break;
		case 6://清空
			allclear(&abs);
			break;
		case 0://退出
			cout << "欢迎您下次使用本功能。" << endl;
			goto b;
			break;
		default:
			break;
		}
	}
	


	b:system("pause");
	return 0;
}