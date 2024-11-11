p=0
N,K=map(int,input().split())
for i in range(1,N+1):
  n=0
  while  i<K:
    i*=2
    n+=1
  p+=(1/N)*(0.5)**n
print(p)