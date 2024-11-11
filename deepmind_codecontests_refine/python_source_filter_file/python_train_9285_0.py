n = int(input())
a = [int(x) for x in input().split()]
x, y = int(0), int(0)
a.sort()
for i in range(n//2):
    x += a[0]
    y += a[n-i-1]
if(n%2):
    y += a[(n//2)]
print(x * x + y * y)
