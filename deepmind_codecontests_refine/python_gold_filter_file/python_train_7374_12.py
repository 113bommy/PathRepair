N=int(input())
X=0
for i in range(N):
  l,n=map(int,input().split())
  X+=n-l+1
print(X)
