#include <stdio.h>
#include <corecrt_malloc.h>
#include <stdlib.h>
#include <time.h>

// Структура для хранения узла двоичного дерева
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Функция для вставки элемента в двоичное дерево
void insert(struct TreeNode** tree, int data) {
    if (*tree == NULL) {
        *tree = (TreeNode*)malloc(sizeof(struct TreeNode));
        (*tree)->data = data;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else {
        if (data < (*tree)->data) {
            insert(&((*tree)->left), data);
        }
        else {
            insert(&((*tree)->right), data);
        }
    }
}

// Функция для вывода элементов двоичного дерева в отсортированном порядке
void print_tree(struct TreeNode* tree) {
    if (tree == NULL) {
        return;
    }
    else {
        print_tree(tree->left);
        printf("%d\n", tree->data);
        print_tree(tree->right);
    }
}

// Основная функция для сортировки массива с помощью двоичного дерева
int main() {
    int arr[100];
    //создаём массив на сто элементов
    srand(time(NULL));
    //для рандома
    for (int i = 0; i < 100;i++) {
        arr[i] = rand() % (201) - 100;
        //для каждого из элементов случайное значений от -100 до 100
    }
    
    int size = sizeof(arr) / sizeof(int);
    struct TreeNode* tree = NULL; // Инициализируем двоичное дерево как пустое
    printf("Неотсортированный");
    for (int i = 0; i < 100; i++) {
        printf("%d\n", arr[i]);
        //вывод
    }
    // Вставляем элементы массива в двоичное дерево
    for (int i = 0; i < size; i++) {
        insert(&tree, arr[i]);
        //функция добавления
    }
    printf("отсортированный");
    // Выводим элементы двоичного дерева в отсортированном порядке
    print_tree(tree);
    //выводим сам граф
}