N=int(input())
H=list(map(int,input().split()))
ans=0
for i in range(1,N):
    if H[i]>=max(H[:i]):
        ans+=1
print(ans+1)