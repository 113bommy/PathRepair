N=int(input())
A=list(map(int,input().split()))
ans=[0]*N
for x in A:
  ans[x-1]+=1
for y in ans:
  print(y)
