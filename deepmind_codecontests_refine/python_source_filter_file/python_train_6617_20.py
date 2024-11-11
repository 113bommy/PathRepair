import math
n,n1,n2=map(int,input().split())
s=input().split()
r=[]
for i in range(n):
    a=int(s[i])
    r.append(a)

r.sort()
r=r[::-1]

if n1>n2:
    d=n2
else:
    d=n1

if d==n2:
    m1=sum(r[0:d])/d
    m2=sum(r[d:n])/n1
else:
    m1=sum(r[0:d])/d
    m2=sum(r[d:n])/n2

a=m1+m2

print ('{0:.8f}'.format(a))

