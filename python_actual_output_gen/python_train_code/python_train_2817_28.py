n = int(input())
a = list(map(int,input().split()))
sa = sum(a)
x = a[0]
m = abs(sa-2*x)
for i in range(1,n):
    x += a[i]
    m = min(m, abs(sa-2*x))
print(m)