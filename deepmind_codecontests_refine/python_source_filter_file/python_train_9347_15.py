n,*a=map(int,open(0).read().split())
b=sum(a)
c=0
d=200000
for i in a:
    c+=i
    d=min(d,abs(c-b/2))
print(int(d*2))