N=int(input())
X=[0]*N
for a in map(int,input().split()):
  X[a-1]+=1
for i in range(N):
  print(X[i])

