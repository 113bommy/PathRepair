N,K=map(int,input().split())
r=0
md=10*9+7
for k in range(K,N+2):
  r += k*(N-k+1)+1  
print(r%md)
