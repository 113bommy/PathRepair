n,m,k=map(int,input().split())
n,m=min(n,m),max(n,m)
for i in range(n//2+n%2):
  num,dem=k-i*m,n-2*i
  if num%dem or not(0<=num//dem<=m):continue
  print("Yes");exit()
print("No")