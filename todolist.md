### 其他内容/工具
- [x] 符号的表示
### 基本任务
- [x] 错误类型 1：变量在使用时未经定义。
- [x] 错误类型 2：函数在调用时未经定义。
- [ ] 错误类型 3：变量出现重复定义，或变量与前面定义过的结构体名字重复。
- [ ] 错误类型 4：函数出现重复定义（即同样的函数名出现了不止一次定义）。
- [x] 错误类型 5：赋值号两边的表达式类型不匹配。
- [x] 错误类型 6：赋值号左边出现一个只有右值的表达式。
- [x] 错误类型 7：操作数类型不匹配或操作数类型与操作符不匹配（例如整型变量与数组变量相加减，或数组（或结构体）变量与数组（或结构体）变量相加减）。
- [x] 错误类型 8：return 语句的返回类型与函数定义的返回类型不匹配。
- [x] 错误类型 9：函数调用时实参与形参的数目或类型不匹配。
- [x] 错误类型 10：对非数组型变量使用“[…]”（数组访问）操作符。
- [x] 错误类型 11：对普通变量使用“(…)”或“()”（函数调用）操作符。
- [x] 错误类型 12：数组访问操作符“[…]”中出现非整数（例如 a[1.5]）。
- [x] 错误类型 13：对非结构体型变量使用“.”操作符。
- [x] 错误类型 14：访问结构体中未定义过的域。
- [ ] 错误类型 15：结构体中域名重复定义（指同一结构体中），或在定义时对域进行初始化（例如 struct A {int a=0;}）。
- [ ] 错误类型 16：结构体的名字与前面定义过的结构体或变量的名字重复。
- [ ] 错误类型 17：直接使用未定义过的结构体来定义变量。
### 选做3-1
- [x] 错误类型 18：函数进行了声明，但没有被定义。
- [ ] 错误类型 19：函数的多次声明互相冲突（即函数名一致，但返回类型、形参数量或者形 参类型不一致），或者声明与定义之间互相冲突。