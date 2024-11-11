n, l = map(int,input().split())
a = list(map(int,input().split()))
b = 0
c = []
a.sort()
for i in range(n):
    b = a[i] - a [i-1]
    c.append(b)
x = max(c)
j = l - max(c)
k = x / 2
l = min(c)
m = max(j,k,l)
print('%.10f'% m)