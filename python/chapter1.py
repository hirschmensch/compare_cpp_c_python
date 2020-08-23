import math

def multiply0(n, a):
	if n == 1:
		return a
	return multiply0(n - 1, a) + a

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


val1 = 10
val2 = 3

print("n =", val1, "a =", val2)
print(val1, "*", val2, "=", multiply0(val1, val2))
print("Number of adds:", val1, "-> O(n)")
print(val1, "*", val2, "=", multiply1(val1, val2))
print("Number of adds:", math.log(val1, 2) + (bin(val1).count("1") - 1), "-> O(log(n))")