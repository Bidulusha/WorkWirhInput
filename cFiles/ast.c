typedef enum {
    NODE_PROGRAM,
    NODE_STATEMENT,
    NODE_EXPRESSION,
    NODE_MOUSE_CLICK,
    NODE_KEYBOARD_INPUT,
    NODE_TIMEOUT,
    NODE_NUMBER,
    NODE_IDENTIFIER,
    NODE_ACTION_LIST
} NodeType;

typedef struct Node {
    NodeType type;           // Тип узла
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
    node->type = NODE_MOUSE_CLICK;
    node->mouse_click.x = x;
    node->mouse_click.y = y;
    return node;
}

Node* create_number_node(int value) {
    Node* node = malloc(sizeof(Node));
    node->type = NODE_NUMBER;
    node->number.value = value;
    return node;
}