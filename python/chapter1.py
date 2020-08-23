def multiply1(n, a):
    if n == 1:
        return a
    result = multiply1(half(n), a + a)
    if odd(n):
        result = result + a
    return result

def odd(n):
    return n & 0x1

def half(n):
    return n >> 1


val1 = 50
val2 = 3

print(val1, "*", val2, "=", multiply1(val1, val2))
