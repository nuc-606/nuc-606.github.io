#include<iostream>
#include<string>
using namespace std;
class Stud
{
private:
    std::string NAME;
    std::string ID;
    double SCORE;
public:
    static double totle;//��̬��������ܷ�����
    static int sum;//��̬���������������
    Stud() { sum++; };//��������
    Stud(const std::string name, const std::string id, double score) :NAME(name), ID(id), SCORE(score)
    {
        sum++; totle += score;
    };//���캯��
    static double Average();//��̬��Ա��������ƽ��������
    void SetInto(const std::string name, const std::string id, double score);//��ͨ��Ա������������
    void Show();//��ͨ��Ա�����������
};
int Stud::sum = 0;
double Stud::totle = 0;//�����ʼ���ܷ֡�����
void Stud::SetInto(const std::string name, const std::string id, double score)//���ⶨ���������ݳ�Ա����
{
    this->NAME = name;
    this->ID = id;
    this->SCORE = score;
    totle += score;
}
void Stud::Show()//���ⶨ��������ݳ�Ա����
{
    std::cout << "������" << NAME << std::endl;
    std::cout << "ѧ�ţ�" << ID << std::endl;
    std::cout << "�ɼ���" << SCORE << std::endl;
}
static double Average()//�����ʼ��ƽ���־�̬��Ա����
{
    return Stud::totle / Stud::sum;
}
int main()
{

    int N = 1;
    cout << "������N��";
    cin >> N;
    std::string* name = new std::string[N];
    std::string* number = new std::string[N];
    double* score = new double[N];
    Stud* sum = new Stud[N];//��������洢�����������
    int i;
    for (i = 0; i < N; i++)
    {
        std::cout << "����";
        std::cin >> name[i];
        std::cout << "ѧ��";
        std::cin >> number[i];
        std::cout << "����";
        std::cin >> score[i];
        sum[i].SetInto(name[i], number[i], score[i]);
    }
    for (i = 0; i < N; i++)
    {
        sum[i].Show();
    }
    std::cout << "ƽ����" << Average() << std::endl;
}