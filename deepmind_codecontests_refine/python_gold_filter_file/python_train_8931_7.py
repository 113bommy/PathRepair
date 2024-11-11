N,K=map(int,input().split())
ans=0
for i in range(1,N+1):
  count=0
  while i<K:
    i=2*i
    count+=1
  ans+=pow(1/2,count)/N
print(ans)