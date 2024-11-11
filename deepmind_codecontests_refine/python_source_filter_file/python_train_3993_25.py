n,m,a=map(int,input().split())
if n%a==0:
    i=n/a
else:
    i=(n//a)+1
if m%a==0:
    j=m/a
else:
    j=(m//a)+1
print(i*j)
