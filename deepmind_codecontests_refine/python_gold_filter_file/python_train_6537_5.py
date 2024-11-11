N=int(input())
B=list(map(int,input().split()))
ans=0
ans+=B[0]+B[-1]
for i in range(N-2):
  ans+=min(B[i],B[i+1])
print(ans)