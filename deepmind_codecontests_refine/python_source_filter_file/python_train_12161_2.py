N,M,C=map(int,input().split())
B=input().split()
res=0
for i in range(N):
  sum=C
  A=input().split()
  for j in range(M):
    sum+=int(B[i])*int(A[i])
    if sum>0:
      res+=1
print(res)