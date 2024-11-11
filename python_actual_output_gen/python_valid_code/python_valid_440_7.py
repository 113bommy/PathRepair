def solve(n,arr):
  if n==1:
    if arr[0]==1:
      return 2
    return 1
  g=1
  prev=arr[0]
  if prev==1:
    g+=1
  
  
  for i in range(1,n):
    if arr[i]==1:
      if prev==1:
        g+=5
      else:
        g+=1
    if prev==0:
        return -1
    prev=arr[i]
  return g

t=int(input())
for i in range(t):
  n=int(input())
  arr=list(map(int,input().split()))
  print(solve(n,arr))