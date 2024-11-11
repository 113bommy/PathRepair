N=int(input())
X=0
for i in range(N):
  l,n=map(int,input().split())
  X+=l-n+1
print(X)