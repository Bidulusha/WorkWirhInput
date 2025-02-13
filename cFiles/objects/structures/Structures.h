#include "../enums/Types.h"
#include "../enums/Functions.h"
#include "Bool.h"
#include "../enums/TokenTypes.h"


typedef struct Node {
    TokenType type;           // Тип узла
    union {
        struct {
            struct Node* statements; // Список операторов
        } program;

        struct {
            struct Node* next;       // Следующий оператор
            struct Node* action;     // Действие (например, клик мыши)
        } statement;

        struct {
            int value;               // Числовое значение
        } number;

        struct {
            char* name;              // Имя идентификатора
        } identifier;

        struct {
            int x;                   // Координаты для клика мыши
            int y;
        } mouse_click;

        struct {
            char key;                // Клавиша для ввода
        } keyboard_input;

        struct {
            int duration;            // Время ожидания
        } timeout;
    };
} Node;

Node* create_mouse_click_node(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->type = TOKEN_MOUSE_CLICK;
    node->mouse_click.x = x;
    node->mouse_click.y = y;
    return node;
}

Node* create_number_node(int value) {
    Node* node = malloc(sizeof(Node));
    node->type = TOKEN_NUMBER;
    node->number.value = value;
    return node;
}