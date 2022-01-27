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
    static double totle;//静态变量存放总分声明
    static int sum;//静态变量存放人数声明
    Stud() { sum++; };//人数遍历
    Stud(const std::string name, const std::string id, double score) :NAME(name), ID(id), SCORE(score)
    {
        sum++; totle += score;
    };//构造函数
    static double Average();//静态成员函数计算平均分声明
    void SetInto(const std::string name, const std::string id, double score);//普通成员函数输入数据
    void Show();//普通成员函数输出数据
};
int Stud::sum = 0;
double Stud::totle = 0;//类外初始化总分、人数
void Stud::SetInto(const std::string name, const std::string id, double score)//类外定义输入数据成员函数
{
    this->NAME = name;
    this->ID = id;
    this->SCORE = score;
    totle += score;
}
void Stud::Show()//类外定义输出数据成员函数
{
    std::cout << "姓名：" << NAME << std::endl;
    std::cout << "学号：" << ID << std::endl;
    std::cout << "成绩：" << SCORE << std::endl;
}
static double Average()//类外初始化平均分静态成员函数
{
    return Stud::totle / Stud::sum;
}
int main()
{

    int N = 1;
    cout << "请输入N：";
    cin >> N;
    std::string* name = new std::string[N];
    std::string* number = new std::string[N];
    double* score = new double[N];
    Stud* sum = new Stud[N];//对象数组存储输入对象数据
    int i;
    for (i = 0; i < N; i++)
    {
        std::cout << "姓名";
        std::cin >> name[i];
        std::cout << "学号";
        std::cin >> number[i];
        std::cout << "分数";
        std::cin >> score[i];
        sum[i].SetInto(name[i], number[i], score[i]);
    }
    for (i = 0; i < N; i++)
    {
        sum[i].Show();
    }
    std::cout << "平均分" << Average() << std::endl;
}