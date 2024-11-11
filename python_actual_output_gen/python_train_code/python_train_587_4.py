N=int(input())
A=list(map(int,input().split(' ')))
B=list(map(int,input().split(' ')))
ans=0
for i in range(N):
  A = sum(A[:i+1]+B[i:])
  ans=max(ans,B)
print(ans)
