#include "manager.h"
Manager::Manager() {}

Manager::Manager(string name, string pass)
{
	this->m_name = name;
	this->m_pass = pass;
	this->Init_map();
	ifstream in;
	in.open(COMPUTER_FILE, ios::in);
	int id, maxnum;
	ComputerRoom c;
	while (in >> id && in >> maxnum)
	{
		c.Set_info(id, maxnum);
		crm.push_back(c);
	}
	cout << "当前机房数量为:" << crm.size() << endl;
	in.close();
}

void Manager::Menu()
{
	cout << "欢迎管理员:" << this->m_name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
}

void Manager::Add_account()
{
	cout << "请输入添加的账号类型:" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;
	int choice;
	cin >> choice;
	string filename, tip, errortip;
	ofstream out;
	if (choice == 1)
	{
		filename = STUDENT_FILE;
		tip = "请输入学号:";
		errortip = "学号重复，请重新输入:";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "请输入职工编号:";
		errortip = "职工号重复，请重新输入:";
	}
	out.open(filename, ios::out | ios::app);
	int id;
	string name, pass;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		if (Check_repeat(id, choice))
			cout << errortip << endl;
		else
			break;
	}
	cout << "请输入姓名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pass;
	out << id << " " << name << " " << pass << endl;
	cout << "添加成功!" << endl;
	system("pause");
	system("cls");
	out.close();
	this->Init_map();
}

void Print_student(pair<int, Student>s)
{
	cout << "学号:" << s.first << " 姓名:" << s.second.Get_info().second.first << " 密码:" << s.second.Get_info().second.second << endl;
}
void Print_teacher(pair<int, Teacher>t)
{
	cout << "职工号:" << t.first << " 姓名:" << t.second.Get_info().second.first << " 密码:" << t.second.Get_info().second.second << endl;
}
void Manager::Show_account()
{
	cout << "请选择查看内容:" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "所有学生信息如下:\n" << endl;
		for_each(stu.begin(), stu.end(), Print_student);
	}
	else
	{
		cout << "所有老师信息如下:" << endl;
		for_each(tea.begin(), tea.end(), Print_teacher);
	}
	system("pause");
	system("cls");
}

void Manager::Show_computer()
{
	cout << "机房信息如下:" << endl;
	for (auto it : crm)
		cout << "机房编号:" << it.Get_info().first << " 机房最大容量:" << it.Get_info().second << endl;
	system("pause");
	system("cls");
}

void Manager::Clear_file()
{
	ofstream out(ORDER_FILE, ios::trunc);
	out.close();
	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}

void Manager::Init_map()
{
	ifstream in;
	in.open(STUDENT_FILE, ios::in);
	if (!in.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	stu.clear();
	tea.clear();
	int id;
	string name, pass;
	Student s;
	while (in >> id && in >> name && in >> pass)
	{
		s.Set_info(id, name, pass);
		stu.insert({ id,s });
	}
	cout << "当前学生数量为:" << stu.size() << endl;
	in.close();
	in.open(TEACHER_FILE, ios::in);
	if (!in.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (in >> id && in >> name && in >> pass)
	{
		t.Set_info(id, name, pass);
		tea.insert({ id,t });
	}
	cout << "当前老师数量为:" << stu.size() << endl;
	in.close();
}

bool Manager::Check_repeat(int id, int type)
{
	if (type == 1)
	{
		if (stu.find(id) != stu.end())
			return true;
	}
	else
	{
		if (tea.find(id) != tea.end())
			return true;
	}
	return false;
}
