N,M,K=map(int,input().split())
ret = 'No'
for m in range(M+1):
  a=K-m*N
  b=M-2*m
  if 0<=a and 0<b and a%b==0:
    n=a//b
    if 0<=n<=N:
      ret = 'Yes'
print(ret)