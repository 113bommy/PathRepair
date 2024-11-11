n = int(input())
a = input().split()
m = 0
for i in range(n):
    a[i] = int(a[i])
a = sorted(a)
m = sum(a)
if n > 2:
    for i in range(n):
        m += (i+1)*a[i]
    m -= a[-1]
print(m)
