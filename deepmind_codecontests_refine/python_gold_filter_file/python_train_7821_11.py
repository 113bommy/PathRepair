n = int(input())
a = list(map(int,input().split()))
res = a[-1]
m = a[-1]
for i in range(n-2, -1, -1):
    if a[i] < m and m > 0:
        res += a[i]
        m = a[i]
    elif a[i] >= m and m > 0:
        res += m -1
        m -= 1
print(res)
