m=998244353
n=int(input())

a=[0]*n
ans=[0]*n
i=n
qp=0
s=0
while(i>=1):
    p=n-i+1
    q=(p* pow(10,p,m))
    
    ans[p-1]=q-qp-s
    
    qp=q
    
    
    s+=ans[p-1]
    
    ans[p-1]=ans[p-1]%m
    
    
    i-=1
    #print(ans[p-1],s)
    
    

print(*ans[::-1])
