N=int(input())
ans=0
for i in range(1,int(N**.5)+1):
    if N%i==0 and i<N//i:
        ans+=N//i-1
print(ans)