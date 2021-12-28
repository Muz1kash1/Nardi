#pragma once
#include "Logic.h"
#include <iostream>
#ifndef Spisok_H
#define Spisok_H


struct list
{
	Sole_fild field; // поле данных
	list* ptr; // указатель на следующий элемент
	list* b_ptr;
};



list* init() // а- значение первого узла
{
	struct list* lst;
	// выделение памяти под корень списка
	lst = (list*)malloc(sizeof(struct list));
	lst->field.get_fishki() = {};
	lst->ptr = lst; // указатель на сам корневой узел
	return(lst);
}

list* addelem(list* lst, Sole_fild number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr; // сохранение указателя на следующий элемент
	lst->ptr = temp; // предыдущий узел указывает на создаваемый
	temp->field = number; // сохранение поля данных добавляемого узла
	temp->ptr = p; // созданный узел указывает на следующий элемент
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
	while (temp->ptr != lst) // просматриваем список начиная с корня
	{ // пока не найдем узел, предшествующий lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // переставляем указатель
	free(lst); // освобождаем память удаляемого узла
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