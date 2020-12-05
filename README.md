# Data-Structures-and-Algorithms 🎆

Data Structures and Algorithms implemented using `c++` for UOM's CS2022 - Data Structures and Algorithms Module

[![BCH compliance](https://bettercodehub.com/edge/badge/bimalka98/Data-Structures-and-Algorithms?branch=main)](https://bettercodehub.com/)
<code>
 <a href="https://www.hackerrank.com/180631j_entc_18">
 <img height="30" src="https://d3keuzeb2crhkn.cloudfront.net/hackerrank/assets/styleguide/logo_wordmark-f5c5eb61ab0a154c3ed9eda24d0b9e31.svg">
 </a>
</code>

## *Useful References*
* [cppreference.com](https://en.cppreference.com/w/)
* [c++ fundamentals- Next.tech](https://next.tech/catalog/c-plus-plus-fundamentals)

## *Editor and Compiler configuration*

| |Configuration|
| :------------ | :---------- |
|Editor 1      | Atom (with TabNine Package installed)  |
|Editor 2|Visual Studio Code(with C/C++ and TabNine Packages installed)|
|Compiler |g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 in WSL(Windows Subsystem for Linux)|



> Atom TabNine client is an advanced AI based auto-completer for all programming languages

> VS code C/C++ extension with IntelliSense, debugging, and code browsing

> g++ command is a GNU c++ compiler invocation command, which is used for preprocessing, compilation, assembly and linking of source code to generate an executable file.

## *Compilation and Execution*

* `main.cpp` - Contains the Code
* `main.out` - Executable file generated by the compiler

Run following commands in the Linux Shell opened in the same directory as the `main.cpp`

```

:~$ g++ -Wall -o main.out -std=c++0x main.cpp                      //compilation
:~$ ./main.out                                                     //Execution

```

---

## *Important syntaxes in modern c++ (can not be used with older versions)*

**Type deduction**  Replace the type name during initialization

```cpp
auto variable_name = value;
```


**decltype specifier** Used to deduce a type of a given entity

```cpp
type variable_name1;
decltype(variable_name1) variable_name2;
```


**Pointers**  Stores the address of a variable

```cpp
int * pointer = &variable; // Type of the object that it points is "int" here.
```


**References** Reference variables

```c++
int a = 5;
int &var = a; //var references the variable a
```


**for loop** The fields in the header of a for loop are optional and can be left blank, but the semicolons cannot be omitted. When the condition is omitted, it always evaluates to true. For example, the following corresponds to an infinite loop where the statement is executed unconditionally:

```cpp
for ( ; ; ) statement;
```

Another variant of the for loop is called a range-based for loop, the syntax for which is as follows:

```cpp
for ( declaration : range ) statement;
for ( int i : int ages[3] = {1,2,3} ) std::cout << i;
```
A while loop can always be expressed using a for loop. Here is an example: `for ( ; condition ; ) statement;`



**break and continue**

The break keyword is used to end a loop independently, regardless of whether it fulfils its condition. In the following program, when condition2 becomes true, the break statement will *immediately terminate the while loop*:

```c++
while (condition1){
    statement1;
    if (condition2)
        break;
}
```

Alternatively, the continue statement is used to skip the rest of the body's loop in the current iteration. In the following example, when condition2 evaluates to true, continue is called, causing the program to reach the end of the loop, skipping statement2 and *continuing with the next iteration*:

```c++
while (condition1){
    statement1;
    if (condition2)
        continue;
    statement2;
}
```
**Concatenating two vectors**
```c++
vector<int> dest, src;
//fill with data
dest.insert(dest.end(),
                    src.begin(),
                    src.end());


// Move elements from src to dest.
// src is left in undefined but safe-to-destruct state.
dest.insert(
    dest.end(),
    std::make_move_iterator(src.begin()),
    std::make_move_iterator(src.end())
  );

// Print out concatenated vector.
std::copy(
    dest.begin(),
    dest.end(),
    std::ostream_iterator<int>(std::cout, "\n")
  );

```
**initialization of a vector with all zeros**
```c++
vector<int> countingSort(vector<int> arr) {
    vector<int> list(100,0); // 100 elements with all zeros
    vector<int>::iterator it;
    for(it = arr.begin(); it != arr.end(); it++) list[*it]++;
    return list;
}
```
