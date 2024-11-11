n = int(input())
a = list(map(int, input().split()))

x = 0
for i in range(n-1):
    x = a[i] - x

res = x // 2
for i in range(n):
    print(2*res, end=' ')
    res = a[i] - res