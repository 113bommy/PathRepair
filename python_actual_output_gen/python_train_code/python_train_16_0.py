n=input()
a=[int(x) for x in input().split()]
b=[int(x) for x in input().split()]
c=[int(x) for x in input().split()]
x=0
y=0
a.sort()
b.sort()
c.sort()
for i in  range(len(b)):
    if(a[i]!=b[i]):
        x=a[i]
        break

if(x==0):
    x=a[-1]
for i in range(len(c)):
    if (c[i] != b[i]):
        y = b[i]
        break

if (y == 0):
    y = a[-1]

print(x)
print(y)