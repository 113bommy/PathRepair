N,K=map(int, input().split())
n=0
while K**(n+1)<N:
  n+=1
  
print(n+1)