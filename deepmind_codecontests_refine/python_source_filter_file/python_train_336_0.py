

n = int(input())
mod=1
p=10**9+7
ans=1
for i in range(1,n+1):
    if i!=n:
        mod=mod*2%p
    ans=ans*i%p
print(ans-mod)
