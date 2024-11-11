# AOJ2019
shukuba = []
n = 0
m = 0

def solve():
    shukuba.sort(key = lambda x: x[0])
    s = sum(map(lambda x: x[0], shukuba)) - m
    if s <= 0:
        return 0
    e = 0
    i = 0
    while s > 0:
        d = shukuba[i][0] if s >= shukuba[i][0] else s
        e += shukuba[i][1] * d
        s -= d
        i += 1
    return e

while True:
    shukuba = []
    line = input()
    n, m = map(int, line.split())
    if n == 0 and m == 0:
        break
    for _ in range(0, n):
        c = list(map(int, list(input().split())))
        shukuba.append(c)
    print(solve())
