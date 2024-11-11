n,k=map(int, input().split())
A=sorted(list(map(int, input().split())))
mod=10**9+7

if A[-1]<0 and k%2==1:
    now=1
    for i in range(k):
        now*=A[-i-1]%mod
        now%=mod
#    print(now)
    exit()
	
l=0
r=n-1
ans=1
if k%2==1:
    ans=A[-1]
#    print(ans)
    r-=1	
for i in range(k//2):
    mi=A[l]*A[l+1]
#    print(mi)
    pl=A[r]*A[r-1]
#    print(pl)
    if mi>pl:
        ans*= mi%mod
        ans%=mod
        l+=2
    else:
        ans*= pl%mod
        ans%=mod
        r-=2
		
print(ans%mod)
