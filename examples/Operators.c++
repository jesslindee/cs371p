// -------------
// Operators.c++
// -------------

// http://en.cppreference.com/w/cpp/language/operators

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void test () {
    {
    int i = 2;
    int j = -i;      // negation
    assert(i ==  2);
    assert(j == -2);
//  ++-i;            // error: lvalue required as increment operand
    }

    {
    int i = 2;
    int j = ++i;    // pre-increment
    assert(i == 3);
    assert(j == 3);
    ++++i;
    assert(i == 5);
    (++i)++;
    assert(i == 7);
    }

    {
    int i = 2;
    int j = i++;    // post-increment
    assert(i == 3);
    assert(j == 2);
//  i++++;          // error: lvalue required as increment operand
//  ++(i++);        // error: lvalue required as increment operand
    }

    {
    int i = 2;
    int j = 3;
    int k = (i = j);
    assert(i == 3);
    assert(j == 3);
    assert(k == 3);
    ++(i = j);
    assert(i == 4);
    }

    {
    int i = 2;
    int j = 3;
    int k = i + j;  // addition
    assert(i == 2);
    assert(j == 3);
    assert(k == 5);
//  ++(i + j);      // error: lvalue required as increment operand
    }

    {
    int i = 2;
    int j = 3;
    int k = (i += j);
    assert(i == 5);
    assert(j == 3);
    assert(k == 5);
    ++(i += j);
    assert(i == 9);
    }

    {
    int i = 12;
    int j = 10;
    int k = i / j;   // integer division
    assert(i == 12);
    assert(j == 10);
    assert(k ==  1);
//  ++(i / j);       // error: lvalue required as increment operand
    }

    {
    int i = 12;
    int j = 10;
    int k = (i /= j);
    assert(i ==  1);
    assert(j == 10);
    assert(k ==  1);
    ++(i /= j);
    assert(i ==  1);
    }

    {
    int i = 12;
    int j = 10;
    int k = i % j;   // integer mod
    assert(i == 12);
    assert(j == 10);
    assert(k ==  2);
//  ++(i % j);       // error: lvalue required as increment operand
    }

    {
    int i = 12;
    int j = 10;
    int k = (i %= j);
    assert(i ==  2);
    assert(j == 10);
    assert(k ==  2);
    ++(i %= j);
    assert(i ==  3);
    }

    {
    int i = 2;
    int j = 3;
    int k = i << j;  // bit shift left
    assert(i == 2);
    assert(j == 3);
    assert(k == 16);
//  ++(i << j);      // error: lvalue required as increment operand
    }

    {
    int i = 2;
    int j = 3;
    int k = (i <<= j);
    assert(i ==  16);
    assert(j ==   3);
    assert(k ==  16);
    ++(i <<= j);
    assert(i == 129);
    }

    {
    int i = 10;       // 0000 0000 0000 1010
    int j = ~i;       // 1111 1111 1111 0101: bit complement
    int k = ~i + 1;   // 1111 1111 1111 0110
    assert(i ==  10);
    assert(j == -11);
    assert(k == -10);
//  ++~i;             // error: lvalue required as increment operand
    }

    {
    int i = 10;      // 1010
    int j = 12;      // 1100
    int k = i & j;   // 1000: bit and
    assert(i == 10);
    assert(j == 12);
    assert(k ==  8);
//  ++(i & j);       // error: lvalue required as increment operand
    }

    {
    int i = 10;
    int j = 12;
    int k = (i &= j);
    assert(i ==  8);
    assert(j == 12);
    assert(k ==  8);
    ++(i &= j);
    assert(i ==  9);
    }

    {
    int i = 10;      // 1010
    int j = 12;      // 1100
    int k = i | j;   // 1110: bit or
    assert(i == 10);
    assert(j == 12);
    assert(k == 14);
//  ++(i | j);       // error: lvalue required as increment operand
    }

    {
    int i = 10;
    int j = 12;
    int k = (i |= j);
    assert(i == 14);
    assert(j == 12);
    assert(k == 14);
    ++(i |= j);
    assert(i == 15);
    }

    {
    int i = 10;      // 1010
    int j = 12;      // 1100
    int k = i ^ j;   // 0110: bit exclusive or
    assert(i == 10);
    assert(j == 12);
    assert(k ==  6);
//  ++(i ^ j);       // error: lvalue required as increment operand
    }

    {
    int i = 10;
    int j = 12;
    int k = (i ^= j);
    assert(i ==  6);
    assert(j == 12);
    assert(k ==  6);
    ++(i ^= j);
    assert(i == 11);
    }

    {
    int i = 10;      // 1010
    int j = 12;      // 1100
    i ^= j;
    assert(i ==  6); // 0110
    assert(j == 12); // 1100
    j ^= i;
    assert(i ==  6); // 0110
    assert(j == 10); // 1010
    i ^= j;
    assert(i == 12); // 1100
    assert(j == 10); // 1010
    }

    {
    int i = 10;
    int j = 12;
    i += j;
    assert(i == 22);
    assert(j == 12);
    j = i - j;
    assert(i == 22);
    assert(j == 10);
    i -= j;
    assert(i == 12);
    assert(j == 10);
    }

    {
    int  i = 8;
    bool j = !(i & (i - 1));
    assert(j == true);       // power of 2
    }

    {
    int i = 13;       // 1101
    int j =  0;
    while (i != 0) {
        i &= (i - 1);
        ++j;}
    assert(j == 3);   // number of bits
    }

    {
    bool a = true;
    bool b = true;
    bool c = false;
    assert(a && b);
    assert(!(a && c));
    assert(a || b);
    assert(a || c);
    assert(a && b);
    assert(!(a && c));
    }

    {
    int a[] = {2, 3, 4};
    assert(a[1] == 3);   // array index
    ++a[1];
    assert(a[1] == 4);
    }

    {
    const int a[] = {2, 3, 4};
    assert(a[1] == 3);
//  ++a[1];                    // error: increment of read-only location
    }}

int main () {
    cout << "Operators.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
