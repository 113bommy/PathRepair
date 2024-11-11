n,m=[int(x) for x in input().split()]
c,r=0,0
while n:
    c+=n
    j=n
    n=(n+r)//m
    r=j%m
print(c)