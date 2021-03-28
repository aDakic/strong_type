# Strong Type
A strongly-typed programming language is one in which each type of data (such as integer, character, hexadecimal, packed decimal, and so forth) is predefined as part of the programming language and all constants or variables defined for a given program must be described with one of the data types. Certain operations may be allowable only with certain data types.

In C++ it can be achieved with wrapper class that gives specific meaning through it name. Strong type is header only library for defining such a wrappers. 

## Examples

### Coordinate example
without strong_type:

```c++
void draw(Coordinate, Coordinate);
...
coordinate x;
coordinate y;
draw(x, y); //OK
draw(y, x); //Also OK!!
```
with strong_type:

```c++
using X = strong_type::strong_type<coordinate, struct x_tag>;
using Y = strong_type::strong_type<coordinate, struct y_tag>;
void draw(X, Y);
...
X x;
Y y;
draw(x, y); //OK
draw(y, x); //Compile error!!
```

Underlying value can be accessed with:
```c++
auto value = x.get()
```
### Position example with operation

```c++
using offset = strong_type<int, 
                struct offset_tag,
                strong_type::addable, // offset + offset = offset
                strong_type::subtractable, // offset - offset = offset
                strong_type::multiplicable_with<int>>; // offset * int = offset

using postion = strong_type<int,
                    struct postion_tag,
                    strong_type::addable_with<offset>>; // postion + offset = postion
```

## Strong type operation
Name  | Description
------------- | -------------
addable`<T>`  | Two `T` can be added
addable_with`<U>`  | `T` can be added with `U` to obtain `T`
subtractable`<T>`  | Two `T` can be subtracted
subtractable_to`<U>`  | `T` can be subtracted to `U` to obtain `T`
multiplicable`<T>`  | Two `T` can be multiplied
multiplicable_with`<U>`  | `T` can be multiplied with `U` to obtain `T`
dividable`<T>` | Two `T` can be divided
dividabl_by`<U>`  | `T` can be divided with `U` to obtain `T`
comparable`<T>` | Two `T` objects can be compared for equality (supports `==`, `!=`, `>`, `>=`, `<`, and `<=`)
bitwiseable`<T>` | Two `T` objects can be `OR`-ed, `AND`-ed or `XOR`-ed
incrementable`<T>` | `T` object can be pre-incremented and post-incremented
decrementable`<T>` | `T` object can be pre-decremented and post-decremented
