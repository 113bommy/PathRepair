import sys
input = sys.stdin.readline


def f(a):
    s = []
    n = a
    for i in range(2, int(n ** .5) + 1):
        if a % i == 0:
            while a % i == 0:
                a //= i
            s.append(i)
        i += 1
    if a > 0:
        s.append(a)
    return s


def check(elem):
    for item in a:
        if item[0] % elem != 0 and item[1] % elem != 0:
            return False
    return True


n = int(input())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append((x, y))
s = f(a[0][0]) + f(a[0][1])
for elem in s:
    if check(elem):
        print(elem)
        exit()
print(-1)
