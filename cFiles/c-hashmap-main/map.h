//
//  map.h
//
//  Created by Mashpoe on 1/15/21.
//

#ifndef map_h
#define map_h

#define hashmap_str_lit(str) (str), sizeof(str) - 1
#define hashmap_static_arr(arr) (arr), sizeof(arr)

// Удаление элементов map отключено по умолчанию из-за незначительных накладных расходов.
// Если вы хотите включить эту функцию, раскомментируйте строку ниже:
//#define __HASHMAP_REMOVABLE

#include <stdint.h>
#include <stddef.h>

// Хэш-maps могут ассоциировать ключи с указательными значениями или целочисленными типами.
typedef struct hashmap hashmap;

// Тип обратного вызова, используемый для итерации по map/освобождения записей:
// int <имя функции>(const void* ключ, size_t размер, uintptr_t значение, void* usr)
// usr — это указатель пользователя, который может быть передан через hashmap_iterate.
typedef int (*hashmap_callback)(const void *key, size_t ksize, uintptr_t value, void *usr);

hashmap* hashmap_create(void);

// Освобождает только объект хэш-таблицы и корзины.
// Не вызывает free для ключа или значения каждого элемента.
// Чтобы освободить данные, связанные с элементом, вызовите hashmap_iterate.
void hashmap_free(hashmap* map);

// Не создает копию ключа.
// Вы должны скопировать его самостоятельно, если хотите гарантировать его срок службы,
// или если планируете вызвать hashmap_key_free.
// Возвращает -1 в случае ошибки.
int hashmap_set(hashmap* map, const void* key, size_t ksize, uintptr_t value);

// Добавляет запись, если она не существует, используя значение *out_in.
// Если она существует, устанавливает значение в *out_in, что означает, что значение
// записи будет в *out_in независимо от того, существовала ли она изначально.
// Возвращает -1 в случае ошибки.
// Возвращает 1, если запись уже существовала, возвращает 0 в противном случае.
int hashmap_get_set(hashmap* map, const void* key, size_t ksize, uintptr_t* out_in);

// Похоже на hashmap_set(), но при перезаписи записи
// вы сможете правильно освободить данные старой записи через обратный вызов.
// В отличие от hashmap_set(), эта функция перезапишет оригинальный указатель ключа,
// что означает, что вы можете освободить старый ключ в обратном вызове, если это применимо.
int hashmap_set_free(hashmap* map, const void* key, size_t ksize, uintptr_t value, hashmap_callback c, void* usr);

int hashmap_get(hashmap* map, const void* key, size_t ksize, uintptr_t* out_val);

#ifdef __HASHMAP_REMOVABLE
void hashmap_remove(hashmap *map, const void *key, size_t ksize);

// same as `hashmap_remove()`, but it allows you to free an entry's data first via a callback.
void hashmap_remove_free(hashmap* m, const void* key, size_t ksize, hashmap_callback c, void* usr);
#endif

int hashmap_size(hashmap* map);

// Итерация по карте, вызывая c для каждого элемента.
// Проходит через элементы в порядке их добавления.
// Ключ элемента, размер ключа, значение и usr будут переданы в c.
// Если c возвращает -1, итерация прерывается.
// Возвращает последний результат c
int hashmap_iterate(hashmap* map, hashmap_callback c, void* usr);

// Выводит информацию о корзине для отладки.
// Позволяет увидеть, сколько коллизий у вас возникает.
// 0 — это пустая корзина, 1 — занятая, а x — удаленная.
//void bucket_dump(hashmap *m);

#endif // map_h
