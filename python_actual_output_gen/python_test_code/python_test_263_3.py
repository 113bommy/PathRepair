# from numba import jit
n = int(input())
a, b, c = map(int, input().split())
x, y, z = map(int, input().split())

maxa = min(a, y) + min(b, z) + min(c, x)
mina = min(a, n - z) + min(b, n - x) + min(c, n - y)

print(mina, maxa)