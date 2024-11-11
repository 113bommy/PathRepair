N,M=map(int,input().split())
a=[0]*(M+1)
for i in range(N):
  l=list(map(int,input().split()))
  for j in range(l[0]):
    a[l[j+1]]+=1
print(a.count(N))
