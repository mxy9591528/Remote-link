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
	cout << "��ǰ��������Ϊ:" << crm.size() << endl;
	in.close();
}

void Manager::Menu()
{
	cout << "��ӭ����Ա:" << this->m_name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
}

void Manager::Add_account()
{
	cout << "��������ӵ��˺�����:" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;
	int choice;
	cin >> choice;
	string filename, tip, errortip;
	ofstream out;
	if (choice == 1)
	{
		filename = STUDENT_FILE;
		tip = "������ѧ��:";
		errortip = "ѧ���ظ�������������:";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "������ְ�����:";
		errortip = "ְ�����ظ�������������:";
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
	cout << "����������:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pass;
	out << id << " " << name << " " << pass << endl;
	cout << "��ӳɹ�!" << endl;
	system("pause");
	system("cls");
	out.close();
	this->Init_map();
}

void Print_student(pair<int, Student>s)
{
	cout << "ѧ��:" << s.first << " ����:" << s.second.Get_info().second.first << " ����:" << s.second.Get_info().second.second << endl;
}
void Print_teacher(pair<int, Teacher>t)
{
	cout << "ְ����:" << t.first << " ����:" << t.second.Get_info().second.first << " ����:" << t.second.Get_info().second.second << endl;
}
void Manager::Show_account()
{
	cout << "��ѡ��鿴����:" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "����ѧ����Ϣ����:\n" << endl;
		for_each(stu.begin(), stu.end(), Print_student);
	}
	else
	{
		cout << "������ʦ��Ϣ����:" << endl;
		for_each(tea.begin(), tea.end(), Print_teacher);
	}
	system("pause");
	system("cls");
}

void Manager::Show_computer()
{
	cout << "������Ϣ����:" << endl;
	for (auto it : crm)
		cout << "�������:" << it.Get_info().first << " �����������:" << it.Get_info().second << endl;
	system("pause");
	system("cls");
}

void Manager::Clear_file()
{
	ofstream out(ORDER_FILE, ios::trunc);
	out.close();
	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}

void Manager::Init_map()
{
	ifstream in;
	in.open(STUDENT_FILE, ios::in);
	if (!in.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
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
	cout << "��ǰѧ������Ϊ:" << stu.size() << endl;
	in.close();
	in.open(TEACHER_FILE, ios::in);
	if (!in.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (in >> id && in >> name && in >> pass)
	{
		t.Set_info(id, name, pass);
		tea.insert({ id,t });
	}
	cout << "��ǰ��ʦ����Ϊ:" << stu.size() << endl;
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
