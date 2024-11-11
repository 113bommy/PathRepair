def inp(n):
    if n == 1:
        return map(int, stdin.readline().split())
    elif n == 2:
        return map(float, stdin.readline().split())
    else:
        return map(str, stdin.readline().split())


def arr_inp():
    return [int(x) for x in stdin.readline().split()]


from sys import *

n, n1, n2 = inp(1)
mi, ma = min(n1, n2), max(n1, n2)
a = sorted(arr_inp(), reverse=True)
print('{:.8f}'.format(sum(a[:mi]) / mi + sum(a[mi:ma+mi]) / ma))
