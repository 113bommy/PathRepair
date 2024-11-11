n,l,r=map(int,input().split())
a,b=[],[]

for i in range(r):
    t=2**i 
    a.append(t)
max=sum(a)+(n-r)*(2**(r-1))

for i in range(l):
    s=2**i
    b.append(s)
min=sum(b)+(n-l)*1

print(min,max)