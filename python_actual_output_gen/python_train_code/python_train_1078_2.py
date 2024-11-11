n,m=map(int,input().split())
a=set(map(int,input().split()))
b=set(map(int,input().split()))
c=1;N=0;M=0
for k in range(m*n,0,-1):
  if k in A and k in B:
    N+=1;M+=1
  elif k in A:
    c*=M;N+=1
  elif k in B:
    c*=N;M+=1
  else:
    c*=M*N-m*n+k
  c=c%(10**9+7)
print(c)