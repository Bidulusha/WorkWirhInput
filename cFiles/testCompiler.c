#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NODE_PROGRAM,
    NODE_STATEMENT,
    NODE_MOUSE_CLICK,
    NODE_TIMEOUT,
    NODE_KEYBOARD_INPUT
} NodeType;

typedef struct Node {
    NodeType type;
    union {
        struct {
            struct Node* next;
            struct Node* action;
        } statement;

        struct {
            int x;
            int y;
        } mouse_click;

        struct {
            int duration;
        } timeout;

        struct {
            char key;
        } keyboard_input;
    };
} Node;

// Функции для создания узлов
Node* create_mouse_click_node(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->type = NODE_MOUSE_CLICK;
    node->mouse_click.x = x;
    node->mouse_click.y = y;
    return node;
}

Node* create_timeout_node(int duration) {
    Node* node = malloc(sizeof(Node));
    node->type = NODE_TIMEOUT;
    node->timeout.duration = duration;
    return node;
}

Node* create_keyboard_input_node(char key) {
    Node* node = malloc(sizeof(Node));
    node->type = NODE_KEYBOARD_INPUT;
    node->keyboard_input.key = key;
    return node;
}

/*

{} [] ()   : 

*/

// Функция для обработки файла
Node* parse_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Не удалось открыть файл");
        return NULL;
    }

    Node* head = NULL;
    Node* tail = NULL;

    char command[20];
    while (fscanf(file, "%s", command) != EOF) {
        Node* new_node = NULL;

        if (strcmp(command, "click") == 0) {
            int x, y;
            fscanf(file, "(%d, %d)", &x, &y);
            new_node = create_mouse_click_node(x, y);
        } else if (strcmp(command, "wait") == 0) {
            int duration;
            fscanf(file, "%d", &duration);
            new_node = create_timeout_node(duration);
        } else if (strcmp(command, "type") == 0) {
            char key;
            fscanf(file, " %c", &key);
            new_node = create_keyboard_input_node(key);
        }

        if (new_node) {
            if (!head) {
                head = new_node;
                tail = new_node;
            } else {
                tail->statement.next = new_node;
                tail = new_node;
            }
        }
    }

    fclose(file);
    return head;
}

// Функция для вывода AST
void print_ast(Node* node) {
    while (node) {
        switch (node->type) {
            case NODE_MOUSE_CLICK:
                printf("Mouse Click at (%d, %d)\n", node->mouse_click.x, node->mouse_click.y);
                break;
            case NODE_TIMEOUT:
                printf("Wait for %d milliseconds\n", node->timeout.duration);
                break;
            case NODE_KEYBOARD_INPUT:
                printf("Type '%c'\n", node->keyboard_input.key);
                break;
            default:
                break;
        }
        node = node->statement.next;
    }
}

// Основная функция
int main() {
    const char* filename = "text.vl";
    Node* ast = parse_file(filename);

    if (ast) {
        printf("Abstract Syntax Tree:\n");
        print_ast(ast);
        
        // Освобождение памяти (не забудьте реализовать функцию для удаления узлов)
        // free_ast(ast); // Не забудьте реализовать эту функцию для освобождения памяти.
    }

    return 0;
}