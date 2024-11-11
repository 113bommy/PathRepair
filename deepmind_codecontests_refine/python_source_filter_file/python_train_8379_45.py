n = int(input())

mod = int(1e9)+7
def f2(n):
    if n ==0:
        return 0
    return 20*27**(n-1) % mod + 7 * f(n-1) % mod

def f(n):
    return 3**(3*n) - 7**2

a = f(n)
print( a % mod )

