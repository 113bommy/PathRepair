N,K=map(int,input().split())
 
a=list(map(int,input().split()))
tentou1=0
for i in range(N):
  for j in range(i+1,N):
    if a[i]>a[j]:
      tentou1+=1
stentou=0
for i in range(N):
  for j in range(N):
    if a[i]>a[j]:
      stentou+=1
answer= (tentou1*K) + (K*(K-1)/2*stentou)
print(answer%(10**9+7))

