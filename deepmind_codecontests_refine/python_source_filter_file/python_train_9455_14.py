n,*a=map(int,open(0).read().split())
a.sort()
b=a[-1]
c=a[0]
d=b/2-c
for i in a:
    if d>abs(b/2-i):
        c=i
        d=abs(b/2-i)
print(c,b)