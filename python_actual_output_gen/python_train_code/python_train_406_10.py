n = int(input())
a = list(map(int, input().split(' ')))
mn = n * 2 * 200
for x in range(1, n + 1):
    sm = 0
    for i in range(1, n + 1):
        sm += a[i - 1] * (abs(x - i) + abs(i - 1) + abs(1 - x)) * 2
    mn = min(sm, mn)
print(mn)
