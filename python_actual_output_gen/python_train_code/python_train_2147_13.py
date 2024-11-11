n,m=map(int,input().split())

a=sorted([list(map(int,input().split())) for _ in range(n)])

print(a)
pay=0
i=0
while m>0:
    p=min(m,a[i][1])
    m-=p
    pay+=p*a[i][0]
    i+=1
print(pay)


