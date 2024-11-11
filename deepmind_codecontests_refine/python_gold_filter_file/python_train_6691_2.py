import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
  n=int(input())
  arr=list(map(int,input().split()))
  sums=sum(arr)
  if sums%n!=0:
    print(-1)
    continue
  k=sums//n
  moves=[]
  for i in range(1,n):
    moves.append([1,i+1,(i+1-arr[i]%(i+1))%(i+1)])
    moves.append([i+1,1,(arr[i]+i)//(i+1)])
  for i in range(1,n):
    moves.append([1,i+1,k])
  print(len(moves))
  for i,j,x in moves:
    print(i,j,x)