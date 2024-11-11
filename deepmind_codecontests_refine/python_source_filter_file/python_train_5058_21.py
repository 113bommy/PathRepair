n = int(input())
a = []
b = []
c = []
d = []
for i in range(n):
    x, y = map(int,input().split(' '))
    a.append(x)
    b.append(y)
m = int(input())
for i in range(m):
    x, y = map(int,input().split(' '))
    c.append(x)
    d.append(y)
ans1 = max(b) - min(c)
ans2 = max(d) - min(a)
print(max(ans1,ans2,0))    