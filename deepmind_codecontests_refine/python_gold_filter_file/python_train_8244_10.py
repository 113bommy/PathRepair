t = int(input())
for i in range(t):
    c = list(map(int, input().split()))
    x = abs(c[0] - c[1])
    k = 0
    p = (k + 1) * k // 2
    while p < x or (p - x) % 2 != 0:
        k += 1
        p = (k + 1) * k // 2
    print(k)