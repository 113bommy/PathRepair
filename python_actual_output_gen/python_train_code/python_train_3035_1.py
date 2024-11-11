x=input()
x,k=x.split()
x=int(x)
k=int(k)
mul=pow(2,k+1,1000000007)
y=(x%1000000007*mul)%1000000007
ans=y
if ans!=0:
    ans=(ans%1000000007-(pow(2,k,1000000007)-1)%1000000007)%1000000007
    
print(ans)