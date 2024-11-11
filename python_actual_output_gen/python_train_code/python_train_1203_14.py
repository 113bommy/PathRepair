k,a,b=map(int,input().split())
m=b//k
if a>0:
    x=(a//k)
    m-=x
    if a%k==0:
        m+=1
else:
    m-=(a//k)
    m+=1
print(m)