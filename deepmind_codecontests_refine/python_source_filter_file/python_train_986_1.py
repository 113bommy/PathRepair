def c(k,l):
    d=1
    for i in range(k+1,l+k+1): d*=i
    for i in range(l): d/=(i+1)
    return int(d)%1000000007
    
ans=1
n=int(input())
k=int(input())
for t in range(1,n):
    a=int(input())
    ans*=c(k,a-1)%1000000007
    k+=a
print(ans%1000000007)
    