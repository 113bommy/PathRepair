N,K=map(int,input().split())
 
a=list(map(int,input().split()))
tentou1=0
for i in range(N):
  for j in range(i+1,N):
    if(a[i]>a[j]):
      tentou1+=1
stentou=0
for i in range(N):
  for j in range(N):
    if(a[i]>a[j]):
      stentou+=1
answer=int(tentou1*K + stentou*K*(K-1)//int(2))
print(answer%1000000007)
