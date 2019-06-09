#include<stdio.h>
#include <iostream>
#include <cstring>

struct student //结构体
{
  char name[20];   //姓名
  char number[20]; //学号
  double math;     //数学
  double english;  //英语
  double chinese;  //语文
  double program;  //程序
} s[50];

void head() //界面
{
  printf(
      "**********************************************************************\n"
      "** **\n"
      "** **\n"
      "** 学生成绩管理系统 **\n"
      "** **\n"
      "** 1.信息录入 **\n"
      "** 2.信息统计 **\n"
      "** 3.信息浏览 **\n"
      "** 4.信息查询 **\n"
      "** 5.信息排序 **\n"
      "** 6.信息删除 **\n"
      "** 0.退出系统 **\n"
      "** **\n"
      "**********************************************************************\n");
}
void daoru(struct student s[], int *n)
 //文件导入函数
{
  FILE *p;
  int i = *n;
  if ((p = fopen("data.txt", "r")) == NULL)
  {
    n = n;
  }
  else
  {
    while (!feof(p))
    {
      fscanf(p, "%s%s%lf%lf%lf%lf\n", s[i].name, s[i].number, &s[i].math, &s[i].english, &s[i].chinese, &s[i].program);
      i++;
      *n = *n + 1;
    }
  }
  fclose(p);
}
void daochu(struct student s[], int n)
{
  FILE *p;
  int i = 0;
  if ((p = fopen("data.txt", "w")) == NULL)
  {
    printf("无法打开此文件！");
  }
  else
  {
    while (i < n - 1)
    {
      fprintf(p, "%s %s %lf %lf %lf %lf\n", s[i].name, s[i].number, s[i].math, s[i].english, s[i].chinese, s[i].program);
      i++;
    }
    fprintf(p, "%s %s %lf %lf %lf %lf", s[i].name, s[i].number, s[i].math, s[i].english, s[i].chinese, s[i].program);
  }
  fclose(p);
}
void dayin(struct student s[], int n)
 //显示所有信息
{
  int i;
  double all = 0.0;
  printf("\n姓名\t\t学号\t\t数学\t英语\t语文\t程序\t总分\n");
  for (i = 0; i < n; i++)
  {
    all = s[i].math + s[i].english + s[i].chinese + s[i].program;
    printf("%s\t\t%s\t\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", s[i].name, s[i].number, s[i].math, s[i].english, s[i].chinese, s[i].program, all);
  }
}
void shuru(struct student s[], int *n)
 //信息输入函数
{
  int i = *n, j, k, m;
  printf("请输入学生姓名:");
  scanf("%s", s[i].name);
  printf("请输入学生学号:");
  for (j = 0;; j++)
  {
    m = 0;
    scanf("%s", s[i].number);
    for (k = 0; k < i; k++)
    {
      if (strcmp(s[i].number, s[k].number) == 0)
      {
        m = m + 1;
        printf("学号重复，请重新输入学号:");
        break;
      }
    }
    if (m == 0)
    {
      break;
    }
  }
  printf("请输入数学成绩:");
  scanf("%lf", &s[i].math);
  printf("请输入英语成绩:");
  scanf("%lf", &s[i].english);
  printf("请输入语文成绩:");
  scanf("%lf", &s[i].chinese);
  printf("请输入程序成绩:");
  scanf("%lf", &s[i].program);
  printf("添加信息成功！\n");
  *n = *n + 1;
  daochu(s, *n);
}
void paixu(struct student s[], int n)
 //排序函数
{
  int i, j;
  //定义变量 i j i表示学生数量 j 表示学生成绩 
  double all1, all2;
  struct student stu;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      all1 = s[i].math + s[i].english + s[i].chinese + s[i].program;
      all2 = s[j].math + s[j].english + s[j].chinese + s[j].program;
      if (all1 < all2)
      {
        stu = s[i];
        s[i] = s[j];
        s[j] = stu;
       //选择排序法实现学生成绩排序 
      }
    }
  }
  printf("排序后的数据：\n");
  dayin(s, n);
}
void chazhao(struct student s[], int n)
 //查找函数
{
  char name[20], num[20];
  //定义的数组可以输入数字 字母 或字符 
  int m1, m2 = 0, i, j;
  printf("1.按姓名查找\n2.按学号查找\n选择查询方式（1或2）:");
  scanf("%d", &m1);
  if (m1 == 1)
  {
    printf("请输入您要查找的学生姓名:");
    scanf("%s", name);
    for (i = 0; i < n; i++)
    {
      if (strcmp(s[i].name, name) == 0)
      //如果输入的信息为真则输出相关信息 
      {
        m2 = m2 + 1;
        if (m2 == 1)
        {
          printf("\n姓名\t\t学号\t数学\t英语\t语文\t程序\t总分\n");
        }
        printf("%s\t\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",
		s[i].name, s[i].number, s[i].math, s[i].english, s[i].chinese, s[i].program,
		 s[i].math + s[i].english + s[i].chinese + s[i].program);
      }
    }
    if (m2 == 0)
    {
      printf("没有此学生信息!\n");
    }
  }
  else if (m1 == 2)
  {
    printf("请输入您要查找的学生学号:");
    scanf("%s", num);
    j = 0;
    for (i = 0; i < n; i++)
    {
      if (strcmp(s[i].number, num) == 0)
      {
        m2 = m2 + 1;
        if (m2 == 1)
        {
          printf("\n姓名\t\t学号\t数学\t英语\t语文\t程序\n");
        }
         printf("%s\t\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", 
		 s[i].name, s[i].number, s[i].math, s[i].english, s[i].chinese, s[i].program, 
		 s[i].math + s[i].english + s[i].chinese + s[i].program);
      }
    }
    if (m2 == 0)
    {
      printf("没有此学生信息!\n");
    }
  }
}
void shanchu(struct student s[], int *n)
 //删除函数
{
  char num[20];
  int m = 0, i, j;
  printf("请输入您要删除的学生学号:");
  scanf("%s", num);
  for (i = 0; i <= *n; i++)
  {
    if (strcmp(s[i].number, num) == 0)
    {
      m = m + 1;
      for (j = i; j < *n; j++)
      {
        s[j] = s[j + 1];
    //结构体整体赋值将后一位学生成绩的信息拷贝放入前一位学生的成绩存储位置 
      }
      *n = *n - 1;
    //删除后学生学生总数减一 
    }
  }
  if (m == 0)
  {
    printf("没有此学生信息!\n");
  }
  else
  {
    daochu(s, *n);
    printf("删除完毕!\n");
  }
}
void allAndAver(struct student s[], int n)
//总分和平均分统计 
{
  int i;
  double all = 0.0, aver = 0.0;
  for (i = 0; i < n; i++)
  {
    all = s[i].math + s[i].english + s[i].chinese + s[i].program;
    aver = all / 4;
    printf("%s\t\t%s\t\t%.1lf\t%.1lf\n", s[i].name, s[i].number, all, aver);
  }
}
void Fail(struct student s[], int n)
 //统计单科不及格人数
{
  int i, fail[4] = {0};
  for (i = 0; i < n; i++)
  {
    if (s[i].math < 60)
    {
      fail[0]++;
    }
    if (s[i].english < 60)
    {
      fail[1]++;
    }
    if (s[i].chinese < 60)
    {
      fail[2]++;
    }
    if (s[i].program < 60)
    {
      fail[3]++;
    }
  }
  printf("\n不及格信息：\n");
  printf("数学不及格的人数为：%d人\n", fail[0]);
  printf("英语不及格的人数为：%d人\n", fail[1]);
  printf("语文不及格的人数为：%d人\n", fail[2]);
  printf("程序不及格的人数为：%d人\n", fail[3]);
}
void Max(struct student s[], int n)
 //统计单科最高分人数
{
  int i, counter[4] = {0};
  double max[4] = {s[0].math, s[0].english, s[0].chinese, s[0].program};
  for (i = 0; i < n; i++)
  {
    if (s[i].math > max[0])
    {
      max[0] = s[i].math;
    }
    if (s[i].math > max[1])
    {
      max[1] = s[i].math;
    }
    if (s[i].math > max[2])
    {
      max[2] = s[i].math;
    }
    if (s[i].math > max[3])
    {
      max[3] = s[i].math;
    }
  }
  for (i = 0; i < n; i++)
  {
    if (s[i].math == max[0])
    {
      counter[0]++;
    }
    if (s[i].math == max[1])
    {
      counter[1]++;
    }
    if (s[i].math == max[2])
    {
      counter[2]++;
    }
    if (s[i].math == max[3])
    {
      counter[3]++;
    }
  }
  printf("\n最高分信息：\n");
  printf("数学最高分为：%.1lf, 人数为：%d人\n", max[0], counter[0]);
  printf("英语最高分为：%.1lf, 人数为：%d人\n", max[1], counter[1]);
  printf("语文最高分为：%.1lf, 人数为：%d人\n", max[2], counter[2]);
  printf("程序最高分为：%.1lf, 人数为：%d人\n", max[3], counter[3]);
}
void Min(struct student s[], int n)
 //统计单科最低分人数
{
  int i, counter[4] = {0};
  double min[4] = {s[0].math, s[0].english, s[0].chinese, s[0].program};
  for (i = 0; i < n; i++)
  {
    if (s[i].math < min[0])
    {
      min[0] = s[i].math;
    }
    if (s[i].math < min[1])
    {
      min[1] = s[i].math;
    }
    if (s[i].math < min[2])
    {
      min[2] = s[i].math;
    }
    if (s[i].math < min[3])
    {
      min[3] = s[i].math;
    }
  }
  for (i = 0; i < n; i++)
  {
    if (s[i].math == min[0])
    {
      counter[0]++;
    }
    if (s[i].math == min[1])
    {
      counter[1]++;
    }
    if (s[i].math == min[2])
    {
      counter[2]++;
    }
    if (s[i].math == min[3])
    {
      counter[3]++;
    }
  }
  printf("\n最低分信息：\n");
  printf("数学最低分为：%.1lf, 人数为：%d人\n", min[0], counter[0]);
  printf("英语最低分为：%.1lf, 人数为：%d人\n", min[1], counter[1]);
  printf("语文最低分为：%.1lf, 人数为：%d人\n", min[2], counter[2]);
  printf("程序最低分为：%.1lf, 人数为：%d人\n", min[3], counter[3]);
}
void tongji(struct student s[], int n)
 //统计函数
{
  printf("统计信息如下：\n");
  printf("\n姓名\t\t学号\t\t总分\t平均分\n");3 i 
  allAndAver(s, n);
  Max(s, n);
  Min(s, n);
  Fail(s, n);
}
int main()
 //主函数
{
  int k, n = 0;
  daoru(s, &n);
  daochu(s, n);
  while (1)
  {
    head();
    printf("\n请按对应的键选择相应的功能:");
    scanf("%d", &k);
    switch (k)
    {
    case 1:
      shuru(s, &n);
      break;
    case 2:
      tongji(s, n);
      break;
    case 3:
      dayin(s, n);
      break;
    case 4:
      chazhao(s, n);
      break;
    case 5:
      paixu(s, n);
      break;
    case 6:
      shanchu(s, &n);
      break;
    case 0:
      break;
    default:
      printf("请输入正确的命令!\n");
    }
  }
  return 0;
}

