import sys
T = int(input())
for i in range(T):
    a, b = map(int, sys.stdin.readline().split())
    n = 1
    total = 0
    X = 0
    x = []
    for j in range(1, 11):
        x.append(b*j%10)
    X = sum(x)
    q = int(a/b)
    r = q % 10
    q = q // 10
    total += X*q
    total += sum(x[:r])
    print(total)