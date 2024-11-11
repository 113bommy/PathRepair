def C(n,m):
    j=1
    o=1
    for i in range(n-m+1,n+1):
        o*=i
        while o%j==0 and j<=m:
            o/=j
            j+=1
    return o
d=[0 for i in range(2001)]
u=[0 for i in range(2001)]
k=int(input())
for i in range(k):
    x,y=map(int, input().split())
    d[1000+x-y]+=1
    u[x+y-1]+=1
o=0
for i in range(1,2001):
    o+=C(d[i],2)
    o+=C(u[i],2)
print (int(o))
