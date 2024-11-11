n,m,c=map(int,input().split())
B=list(map(int,input().split()))
count=0
for i in range(n):
  p=c
  A=list(map(int,input().split()))
  for j in range(m):
    p+=A[j]*B[j]
    if p>0:count+=1
print(count)