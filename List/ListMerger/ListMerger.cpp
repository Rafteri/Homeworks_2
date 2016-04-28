//
// Created by Rafteri on 25.03.2016.
//
#include "ListMerger.h"
#include <iostream>

using namespace std;

void AddToEnd(LinkedList *list, double value) { //Добавляем в конец списка
    Node *node = new Node;
    node->value = value;
    node->next = nullptr;
    if (list->first == nullptr) { //Если списка не существует
        list->first = node;
        list->last = node;
    }
    else {
        list->last->next = node;
        list->last = node;
    }
}

void ReadList(LinkedList *list) { //Считываем список
    cout << "Enter elements of list(via gap)" << endl;
    double value;
    while (cin.peek() != '\n') {
        cin >> value;
        AddToEnd(list, value);
    }
    cin.get();
}

void PrintList(LinkedList *list) { //Выводим список
    cout << "Elements of sorted list:" << endl;
    Node *node = list->first;
    while (node != nullptr) {
        cout << node->value << ' ';
        node = node->next;
    }
}

void AddTail(LinkedList *list, Node *node) { //Добавляем хвост оставшийся после слияния
    while (node != nullptr) {
        AddToEnd(list, node->value);
        node = node->next;
    }
}

LinkedList *Association(LinkedList *list1, LinkedList *list2) { //Обьединяем списки
    LinkedList *list = new LinkedList;
    Node *node1 = list1->first;
    Node *node2 = list2->first;
    while (node1 != nullptr && node2 != nullptr) { //Пока не пройдемся по одному списку
        if (node1->value < node2->value) { //Добавляем наименьший элемент, и смещаемся по списку
            AddToEnd(list, node1->value);
            node1 = node1->next;
        }
        else {
            AddToEnd(list, node2->value);
            node2 = node2->next;
        }
    }
    if (node1) { //Проверка, остались ли не добавленные элементы
        AddTail(list, node1);
    } else {
        AddTail(list, node2);
    }
    return list;
}

void *Push(LinkedList *list, Stack *&stack) { //Добавить в стэк список
    LinkedList *newList = new LinkedList;
    newList->first = list->first;
    stack->arr[stack->last + 1].list = newList;
    stack->arr[stack->last + 1].rank++;
    stack->last++;
}

void *PushListOneElem(LinkedList *list, Stack *&stack) { //Добавить в стэк толкьо один элемент списка
    LinkedList *newList = new LinkedList;
    newList->first = list->first;
    list->first = list->first->next;
    newList->first->next = nullptr;
    Push(newList, stack);
}

StackElem *Pop(Stack *stack) { //Забираем из стэка
    StackElem *stackElem = &stack->arr[stack->last];
    stack->arr[stack->last].rank = 0;
    stack->last--;
    return stackElem;
}

LinkedList *MergeSort(LinkedList *list) { //Сортировка слиянием
    Stack *stack = new Stack;
    for (int i = 0; i < 2; i++) { //Добавляем 2 первых списка в стэк
        if (list->first != nullptr) { //Проверка есть ли элементы
            PushListOneElem(list, stack);
        }
    }

    while (list->first != nullptr) { //Пока в списке не закончатся элементы
        while (stack->last > 0 && stack->arr[stack->last - 1].rank == stack->arr[stack->last].rank) { //Проверка на равность рангов
            Push(Association(Pop(stack)->list, Pop(stack)->list), stack); //Объединяем списки и кладем результат в стэк
            stack->arr[stack->last].rank *= 2; //Удваиваем ранг
        }
        PushListOneElem(list, stack); //Кладем в стэк новый список
    }

    for (int i = stack->last; i > 0; i--) { //Объединяем в один список списки, оставшиеся в стэке
        Push(Association(Pop(stack)->list, Pop(stack)->list), stack);
    }

    return Pop(stack)->list; //Возрващаем список

}