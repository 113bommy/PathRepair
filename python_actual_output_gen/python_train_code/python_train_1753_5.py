N,D,A=map(int,input().split())
P=sorted([list(map(int,input().split())) for i in range(N)])
l=r=a=d=0
m=[0]*(N+1)
while l<N:
    while r<N and P[r][0]<=P[l][0]+2*D:
        r+=1
    d+=m[l]
    x=-(-max(0,P[l][1]-d)//A)
    a+=x
    d+=x*A
    dm[r]-=x*A
    l+=1
print(a)
