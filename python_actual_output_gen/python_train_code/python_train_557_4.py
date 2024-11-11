n = int(input())
a = list(map(int, input().split()))
a.sort()
res = (a[n-1]-a[0])*(a[2*n-1]-a[n])
x = max(a)
y = min(a)

for i in range(2,n+1):
    res = min(res, (x-y)*(a[i+n-1]-a[i]))
print(res)
