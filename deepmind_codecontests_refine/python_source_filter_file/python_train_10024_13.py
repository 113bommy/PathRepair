n=int(input())
m=list(map(int,input().split()))
a=max(m)
b=min(m)
c=m.index(a)
m.reverse()
d=m.index(b)
if c>d:
    print(c+d-1)
else:
    print(c+d)