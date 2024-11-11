N,D,A=map(int,input().split())
XH=sorted([list(map(int,input().split())) for i in range(N)])
l,r=0,0
a=0
dp=0
dm=[0]*(N+1)
while l<N:
    while r<N and XH[r][0]<=XH[l][0]+2*D:
        r+=1
    dp+=dm[l]
    x=max(0,-(-XH[l][1]+dp)//A)
    a+=x
    dp+=x*A
    dm[r]-=x*A
    l+=1
print(a)