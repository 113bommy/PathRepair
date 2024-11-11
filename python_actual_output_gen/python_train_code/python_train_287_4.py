n = int(input())
a = list(map(int, input().split()))
m = 0
ma = a[0]
for i in range(1, n):
    ma = max(ma, a[i])
    m = max(m, ma-a[i])
print(m)