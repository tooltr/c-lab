#include<stdio.h>
#include <iostream>
#include <cstring>

struct student //�ṹ��
{
  char name[20];   //����
  char number[20]; //ѧ��
  double math;     //��ѧ
  double english;  //Ӣ��
  double chinese;  //����
  double program;  //����
} s[50];

void head() //����
{
  printf(
      "**********************************************************************\n"
      "** **\n"
      "** **\n"
      "** ѧ���ɼ�����ϵͳ **\n"
      "** **\n"
      "** 1.��Ϣ¼�� **\n"
      "** 2.��Ϣͳ�� **\n"
      "** 3.��Ϣ��� **\n"
      "** 4.��Ϣ��ѯ **\n"
      "** 5.��Ϣ���� **\n"
      "** 6.��Ϣɾ�� **\n"
      "** 0.�˳�ϵͳ **\n"
      "** **\n"
      "**********************************************************************\n");
}
void daoru(struct student s[], int *n)
 //�ļ����뺯��
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
    printf("�޷��򿪴��ļ���");
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
 //��ʾ������Ϣ
{
  int i;
  double all = 0.0;
  printf("\n����\t\tѧ��\t\t��ѧ\tӢ��\t����\t����\t�ܷ�\n");
  for (i = 0; i < n; i++)
  {
    all = s[i].math + s[i].english + s[i].chinese + s[i].program;
    printf("%s\t\t%s\t\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", s[i].name, s[i].number, s[i].math, s[i].english, s[i].chinese, s[i].program, all);
  }
}
void shuru(struct student s[], int *n)
 //��Ϣ���뺯��
{
  int i = *n, j, k, m;
  printf("������ѧ������:");
  scanf("%s", s[i].name);
  printf("������ѧ��ѧ��:");
  for (j = 0;; j++)
  {
    m = 0;
    scanf("%s", s[i].number);
    for (k = 0; k < i; k++)
    {
      if (strcmp(s[i].number, s[k].number) == 0)
      {
        m = m + 1;
        printf("ѧ���ظ�������������ѧ��:");
        break;
      }
    }
    if (m == 0)
    {
      break;
    }
  }
  printf("��������ѧ�ɼ�:");
  scanf("%lf", &s[i].math);
  printf("������Ӣ��ɼ�:");
  scanf("%lf", &s[i].english);
  printf("���������ĳɼ�:");
  scanf("%lf", &s[i].chinese);
  printf("���������ɼ�:");
  scanf("%lf", &s[i].program);
  printf("�����Ϣ�ɹ���\n");
  *n = *n + 1;
  daochu(s, *n);
}
void paixu(struct student s[], int n)
 //������
{
  int i, j;
  //������� i j i��ʾѧ������ j ��ʾѧ���ɼ� 
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
       //ѡ������ʵ��ѧ���ɼ����� 
      }
    }
  }
  printf("���������ݣ�\n");
  dayin(s, n);
}
void chazhao(struct student s[], int n)
 //���Һ���
{
  char name[20], num[20];
  //�������������������� ��ĸ ���ַ� 
  int m1, m2 = 0, i, j;
  printf("1.����������\n2.��ѧ�Ų���\nѡ���ѯ��ʽ��1��2��:");
  scanf("%d", &m1);
  if (m1 == 1)
  {
    printf("��������Ҫ���ҵ�ѧ������:");
    scanf("%s", name);
    for (i = 0; i < n; i++)
    {
      if (strcmp(s[i].name, name) == 0)
      //����������ϢΪ������������Ϣ 
      {
        m2 = m2 + 1;
        if (m2 == 1)
        {
          printf("\n����\t\tѧ��\t��ѧ\tӢ��\t����\t����\t�ܷ�\n");
        }
        printf("%s\t\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",
		s[i].name, s[i].number, s[i].math, s[i].english, s[i].chinese, s[i].program,
		 s[i].math + s[i].english + s[i].chinese + s[i].program);
      }
    }
    if (m2 == 0)
    {
      printf("û�д�ѧ����Ϣ!\n");
    }
  }
  else if (m1 == 2)
  {
    printf("��������Ҫ���ҵ�ѧ��ѧ��:");
    scanf("%s", num);
    j = 0;
    for (i = 0; i < n; i++)
    {
      if (strcmp(s[i].number, num) == 0)
      {
        m2 = m2 + 1;
        if (m2 == 1)
        {
          printf("\n����\t\tѧ��\t��ѧ\tӢ��\t����\t����\n");
        }
         printf("%s\t\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", 
		 s[i].name, s[i].number, s[i].math, s[i].english, s[i].chinese, s[i].program, 
		 s[i].math + s[i].english + s[i].chinese + s[i].program);
      }
    }
    if (m2 == 0)
    {
      printf("û�д�ѧ����Ϣ!\n");
    }
  }
}
void shanchu(struct student s[], int *n)
 //ɾ������
{
  char num[20];
  int m = 0, i, j;
  printf("��������Ҫɾ����ѧ��ѧ��:");
  scanf("%s", num);
  for (i = 0; i <= *n; i++)
  {
    if (strcmp(s[i].number, num) == 0)
    {
      m = m + 1;
      for (j = i; j < *n; j++)
      {
        s[j] = s[j + 1];
    //�ṹ�����帳ֵ����һλѧ���ɼ�����Ϣ��������ǰһλѧ���ĳɼ��洢λ�� 
      }
      *n = *n - 1;
    //ɾ����ѧ��ѧ��������һ 
    }
  }
  if (m == 0)
  {
    printf("û�д�ѧ����Ϣ!\n");
  }
  else
  {
    daochu(s, *n);
    printf("ɾ�����!\n");
  }
}
void allAndAver(struct student s[], int n)
//�ֺܷ�ƽ����ͳ�� 
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
 //ͳ�Ƶ��Ʋ���������
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
  printf("\n��������Ϣ��\n");
  printf("��ѧ�����������Ϊ��%d��\n", fail[0]);
  printf("Ӣ�ﲻ���������Ϊ��%d��\n", fail[1]);
  printf("���Ĳ����������Ϊ��%d��\n", fail[2]);
  printf("���򲻼��������Ϊ��%d��\n", fail[3]);
}
void Max(struct student s[], int n)
 //ͳ�Ƶ�����߷�����
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
  printf("\n��߷���Ϣ��\n");
  printf("��ѧ��߷�Ϊ��%.1lf, ����Ϊ��%d��\n", max[0], counter[0]);
  printf("Ӣ����߷�Ϊ��%.1lf, ����Ϊ��%d��\n", max[1], counter[1]);
  printf("������߷�Ϊ��%.1lf, ����Ϊ��%d��\n", max[2], counter[2]);
  printf("������߷�Ϊ��%.1lf, ����Ϊ��%d��\n", max[3], counter[3]);
}
void Min(struct student s[], int n)
 //ͳ�Ƶ�����ͷ�����
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
  printf("\n��ͷ���Ϣ��\n");
  printf("��ѧ��ͷ�Ϊ��%.1lf, ����Ϊ��%d��\n", min[0], counter[0]);
  printf("Ӣ����ͷ�Ϊ��%.1lf, ����Ϊ��%d��\n", min[1], counter[1]);
  printf("������ͷ�Ϊ��%.1lf, ����Ϊ��%d��\n", min[2], counter[2]);
  printf("������ͷ�Ϊ��%.1lf, ����Ϊ��%d��\n", min[3], counter[3]);
}
void tongji(struct student s[], int n)
 //ͳ�ƺ���
{
  printf("ͳ����Ϣ���£�\n");
  printf("\n����\t\tѧ��\t\t�ܷ�\tƽ����\n");3 i 
  allAndAver(s, n);
  Max(s, n);
  Min(s, n);
  Fail(s, n);
}
int main()
 //������
{
  int k, n = 0;
  daoru(s, &n);
  daochu(s, n);
  while (1)
  {
    head();
    printf("\n�밴��Ӧ�ļ�ѡ����Ӧ�Ĺ���:");
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
      printf("��������ȷ������!\n");
    }
  }
  return 0;
}

