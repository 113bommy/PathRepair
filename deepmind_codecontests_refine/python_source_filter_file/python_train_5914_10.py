N=int(input())
L=list(map(int,input().split()))
ans=0
for i in range(N-2):
  A=L[i:i+4]
  t=A[2]
  A.sort()
  ans+=1 if t==A[1] else 0
print(ans)