D,G=map(int,input().split())

p=[0]*D
c=[0]*D

for i in range(D):
    p[i],c[i]=map(int,input().split())
ans=10e+9

for i in range(2**D):
    sum=0
    q=0
    for j in range(D):
        if(i>>j & 1):
            sum+=(j+1)*100*p[j]+c[j]
            q+=p[j]
        else:
            rest_max=j
    if(sum<G):
        r1=100*(rest_max+1)
        need=-(-(G-sum)//r1)
        if(need>p[rest_max]-1):
            continue
        q+=need
        sum+=need*r1
    
    if(sum>=G):
        ans=min(ans,q)

print(ans)