# 区分`const`和`static`

## 1. `const` 关键字

`const` 关键字用于声明一个常量，意味着一旦变量被初始化，其值就不能再被修改。`const` 可以修饰变量、函数参数、函数返回值等。

### `const` 示例代码

```c
#include <stdio.h>

// 1. 修饰全局变量
const int global_const = 10;

// 2. 修饰局部变量
void const_local_example() {
    const int local_const = 20;
    // local_const = 30;  // 错误：不能修改常量的值
    printf("Local const value: %d\n", local_const);
}

// 3. 修饰函数参数
void print_const_value(const int num) {
    // num = 40;  // 错误：不能修改常量参数的值
    printf("Const parameter value: %d\n", num);
}

// 4. 修饰函数返回值
const int* get_const_pointer() {
    static int value = 50;
    return &value;
}

int main() {
    // 访问全局常量
    printf("Global const value: %d\n", global_const);

    // 调用局部常量示例函数
    const_local_example();

    // 调用带常量参数的函数
    print_const_value(30);

    // 获取常量指针
    const int* ptr = get_const_pointer();
    // *ptr = 60;  // 错误：不能通过常量指针修改值
    printf("Value from const pointer: %d\n", *ptr);

    return 0;
}
/*
Global const value: 10
Local const value: 20
Const parameter value: 30
Value from const pointer: 50
*/
```

### `const` 代码解释

- **全局常量**：`global_const` 是一个全局常量，在程序的整个生命周期内其值都不能被修改。
- **局部常量**：`local_const` 是一个局部常量，在函数内部其值不能被修改。
- **常量参数**：`print_const_value` 函数的参数 `num` 被 `const` 修饰，在函数内部不能修改该参数的值。
- **常量返回值**：`get_const_pointer` 函数返回一个常量指针，不能通过该指针修改其所指向的值。

## 2. `static` 关键字

`static` 关键字在不同的上下文中有不同的作用：

- **修饰全局变量**：限制变量的作用域为当前文件，其他文件无法访问。
- **修饰局部变量**：使变量的生命周期延长至整个程序运行期间，并且只在第一次调用函数时初始化。
- **修饰函数**：限制函数的作用域为当前文件，其他文件无法调用。

### `static` 示例代码

```c
#include <stdio.h>

// 1. 修饰全局变量
static int global_static = 100;

// 2. 修饰局部变量
void static_local_example() {
    static int local_static = 200;
    printf("Local static value: %d\n", local_static);
    local_static++;
}

// 3. 修饰函数
static void static_function() {
    printf("This is a static function.\n");
}

int main() {
    // 访问全局静态变量
    printf("Global static value: %d\n", global_static);

    // 多次调用局部静态变量示例函数
    static_local_example();
    static_local_example();
    static_local_example();
    static_local_example();
    static_local_example();

    // 调用静态函数
    static_function();

    return 0;
}

/*
标准输出：Global static value: 100
Local static value: 200
Local static value: 201
Local static value: 202
Local static value: 203
Local static value: 204
This is a static function.
*/
```

### `static` 代码解释

- **全局静态变量**：`global_static` 是一个全局静态变量，其作用域仅限于当前文件，其他文件无法访问。
- **局部静态变量**：`local_static` 是一个局部静态变量，它的生命周期延长至整个程序运行期间，并且只在第一次调用 `static_local_example` 函数时初始化。每次调用该函数时，`local_static` 的值会保留上一次修改后的结果。
- **静态函数**：`static_function` 是一个静态函数，其作用域仅限于当前文件，其他文件无法调用该函数。

### 3. `const` 和 `static` 的区别

- **`const` 强调值的不可变性**：用于声明常量，确保变量的值在初始化后不能被修改。
- **`static` 强调作用域和生命周期**：用于限制变量或函数的作用域，或者延长变量的生命周期。
