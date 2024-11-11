t = int(input())
for _ in range(t):
    m=int(input())
    a= list(map(int,input().split()))
    b= list(map(int,input().split()))
    s=sum(a)
    z=0
    za=10**5
    for j in range(m):
        za=min(za,max(s-a[j],z))
        s-=a[j]
        z+=b[j]
    print(za)
