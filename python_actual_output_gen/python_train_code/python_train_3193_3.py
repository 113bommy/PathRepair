n = int(input())
a = [int(x) for x in input().split()]
x, y = int(0), int(0)
a.sort()
for i in range(n>>1):
    x += a[0]
    y += a[n-i-1]
if(n&1):
    y += a[(n>>1)]
print(x * x + y * y)
