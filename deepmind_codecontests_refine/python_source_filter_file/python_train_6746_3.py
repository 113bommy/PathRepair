from bisect import*
n,*a=map(int,open(0))
b=bisect
c=[-1]*n
for a in a:c[b(c,a-1)-1]=a
print(n-b(c,1))