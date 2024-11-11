n,m,k=map(int,input().split())
ans=1
m-=n
osn=0
while m>1:
    if osn==max(k,n-k-1):break
    ans+=1
    m-=1
    osnl,osnr=min(k,osn),min(n-k-1,osn)
    osn+=1
    m-=(osnl+osnr)
ans+=m//n
print(ans)
    
