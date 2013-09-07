#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const double LING = 1E-6;
const int CONT = 4;
const int VOLUE = 24;

double number[CONT];
string expression[CONT];

bool m_judge = false; //�ж��Ƿ��н⡣
int count = 0;

void Find(int n) {
    if (n == 1) {
        if (fabs(number[0] - VOLUE) <= LING) { //fabsΪ�����ֵ ��24������Ƿ�С��1E-6
            cout << expression[0] << "\t\t";
            m_judge = true;
            count++;
            cout << endl;
        } else {
        }

    }
    for (int i = 0; i < n; i++)//����
    {
        for (int j = i + 1; j < n; j++)//�������Ĳ��ҽ��м���
        {
            double a, b;
            string expressiona, expressionb;
            a = number[i];
            b = number[j];
            number[j] = number[n - 1];
            expressiona = expression[i];
            expressionb = expression[j];
            expression[j] = expression[n - 1];
            expression[i] = '(' + expressiona + '+' + expressionb + ')';
            number[i] = a + b;
            Find(n - 1);
            expression[i] = '(' + expressiona + '-' + expressionb + ')';
            number[i] = a - b;
            Find(n - 1);
            expression[i] = '(' + expressionb + '-' + expressiona + ')';
            number[i] = b - a;
            Find(n - 1);
            expression[i] = '(' + expressiona + '*' + expressionb + ')';
            number[i] = a*b;
            Find(n - 1);
            if (b != 0) {
                expression[i] = '(' + expressiona + '/' + expressionb + ')';
                number[i] = a / b;
                Find(n - 1);
            }
            if (a != 0) {
                expression[i] = '(' + expressionb + '/' + expressiona + ')';
                number[i] = b / a;
                Find(n - 1);
            }
            number[i] = a;
            number[j] = b;
            expression[i] = expressiona;
            expression[j] = expressionb;
        }
    }
}

int main() {
    cout << "�������ĸ���:\n";
    for (int i = 0; i < CONT; i++) {
        char ch[20];
        cout << "��" << i + 1 << "����:";
        cin >> number[i];
        itoa(number[i], ch, 10); //itoa()�����������ǰѵ�һ������(��ֵ)����(ת��)���ڶ�������(�ַ���)��ȥ������������(int��)�Ǹ���ֵ���ַ�������ʲô���ƴ�š�
        expression[i] = ch;
    }
    cout << endl;
    Find(CONT);
    if (m_judge == true) {
        cout << "\n�ɹ���" << endl;
        cout << "�ܹ��ļ��㷽�����У� " << count << endl;
    } else {
        cout << "ʧ�ܣ�" << endl;
    }
    return 0;
}