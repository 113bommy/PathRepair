n = int(input())
s = []
for i in range(1, n+1):
    s.append(i)
a = list(map(int, input().split()))
l = -1
r = n-1
for i in range(n):
    if i+1!=a[i] and l == -1:
        l = i
        break
for i in range(n-1, l, -1):
    if i+1!=a[i] and l != -1:
        r = i
        break
b = a[::-1]
if s == b:
    print(1, n)
elif s == a[:l]+a[r:l-1:-1] + a[r+1:] and s!=a:
    print(l+1, r+1)
else:
    print(0, 0)
        
