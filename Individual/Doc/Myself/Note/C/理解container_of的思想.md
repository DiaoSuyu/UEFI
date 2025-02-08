# 宏的整体功能

`container_of` 宏的主要作用是：当你已知一个结构体中某个成员的指针时，通过这个指针反向推导出包含该成员的结构体变量的指针。简单来说，就是从结构体的一个成员“回溯”到它所属的整个结构体。

## 宏定义的详细分析

```c
#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})
```

### 1. 宏的参数

- `ptr`：这是一个指向结构体 `type` 中成员 `member` 的指针。在实际使用时，你需要传入这个成员的具体指针。
- `type`：表示包含成员 `member` 的结构体类型。
- `member`：指的是结构体 `type` 中的一个成员名。

### 2. 宏内部的第一行代码

```c
const typeof( ((type *)0)->member ) *__mptr = (ptr);
```

- `((type *)0)`：把地址 `0` 强制转换为结构体 `type` 的指针。这样做的目的是为了能够访问结构体中的成员，因为我们只是想获取成员的类型，并不关心实际的内存地址，所以用 `0` 作为起始地址。
- `((type *)0)->member`：通过这个指针访问结构体中的成员 `member`。
- `typeof( ((type *)0)->member )`：`typeof` 是 GCC 编译器特有的一个扩展，用于获取表达式的类型。这里它获取的是成员 `member` 的类型。
- `const typeof( ((type *)0)->member ) *__mptr = (ptr);`：定义一个常量指针 `__mptr`，其类型与成员 `member` 相同，并将其初始化为传入的指针 `ptr`。这一步主要是为了确保类型的一致性。

### 3. 宏内部的第二行代码

```c
(type *)( (char *)__mptr - offsetof(type,member) );
```

- `(char *)__mptr`：把 `__mptr` 强制转换为 `char *` 类型的指针。这是因为 `char` 类型的指针在进行指针运算时，每次移动的步长是 1 字节，方便我们按字节进行偏移量的计算。
- `offsetof(type,member)`：调用 `offsetof` 宏，计算成员 `member` 相对于结构体 `type` 起始地址的偏移量（以字节为单位）。
- `(char *)__mptr - offsetof(type,member)`：用 `__mptr` 减去偏移量，这样就得到了结构体 `type` 的起始地址。
- `(type *)`：最后把得到的地址强制转换为结构体 `type` 的指针，这样就得到了包含成员 `member` 的结构体变量的指针。

### 示例代码及解释

```c
#include <stdio.h>

// 定义一个结构体
struct MyStruct {
    int num;
    char ch;
    double dbl;
};

// 定义 offsetof 宏
#define offsetof(a,b) ((int)(&(((a*)(0))->b)))

// 定义 container_of 宏
#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})

int main() {
    struct MyStruct obj = {10, 'A', 3.14};

    // 获取成员 'ch' 的指针
    char *ch_ptr = &obj.ch;

    // 通过成员 'ch' 的指针反推结构体指针
    struct MyStruct *struct_ptr = container_of(ch_ptr, struct MyStruct, ch);

    printf("Value of num: %d\n", struct_ptr->num);
    printf("Value of ch: %c\n", struct_ptr->ch);
    printf("Value of dbl: %f\n", struct_ptr->dbl);

    return 0;
}

```

在这个示例中：

1. 我们定义了一个结构体 `MyStruct`，并创建了一个该结构体的对象 `obj`。
2. 获取成员 `ch` 的指针 `ch_ptr`。
3. 调用 `container_of` 宏，传入 `ch_ptr`、结构体类型 `struct MyStruct` 和成员名 `ch`，得到包含该成员的结构体指针 `struct_ptr`。
4. 通过 `struct_ptr` 访问结构体的各个成员并打印其值。

通过这样的方式，我们就从结构体的一个成员指针成功地反推出了整个结构体的指针。
