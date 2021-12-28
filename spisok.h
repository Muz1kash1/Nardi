#pragma once
#include "Logic.h"
#include <iostream>
#ifndef Spisok_H
#define Spisok_H


struct list
{
	Sole_fild field; // ���� ������
	list* ptr; // ��������� �� ��������� �������
	list* b_ptr;
};



list* init() // �- �������� ������� ����
{
	struct list* lst;
	// ��������� ������ ��� ������ ������
	lst = (list*)malloc(sizeof(struct list));
	lst->field.get_fishki() = {};
	lst->ptr = lst; // ��������� �� ��� �������� ����
	return(lst);
}

list* addelem(list* lst, Sole_fild number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr; // ���������� ��������� �� ��������� �������
	lst->ptr = temp; // ���������� ���� ��������� �� �����������
	temp->field = number; // ���������� ���� ������ ������������ ����
	temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
	return(temp);
}
void MovePtr(struct list* L)

{

	L->ptr = L->ptr->ptr;

};

list* deletelem(list* lst)
{
	struct list* temp;
	temp = lst;
	while (temp->ptr != lst) // ������������� ������ ������� � �����
	{ // ���� �� ������ ����, �������������� lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // ������������ ���������
	free(lst); // ����������� ������ ���������� ����
	return(temp);
}
list* init_fields() {
	std::vector<list*> our_fields;
	list* begin = init();
	list* end;
	list* tmp;
	our_fields.push_back(begin);
	for (int i = 0; i < 24; i++) 
	{
		tmp = our_fields[i];
		end = init();
		end->b_ptr = tmp;
		our_fields[i]->ptr = end;
		our_fields.push_back(end);
	}

}



#endif