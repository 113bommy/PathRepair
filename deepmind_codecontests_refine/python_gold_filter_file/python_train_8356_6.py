from sys import stdin


def check(n):
    if n == 0:
        return [0, 0, 0]
    if n < 3:
        return [-1]
    for idx, val in enumerate([7, 5, 3]):
        t = check(n - val)
        if t[0] != -1:
            t[idx] += 1
            return t
    return [-1]


for _ in range(int(stdin.readline())):
    n = int(stdin.readline())
    print(*check(n)[::-1])