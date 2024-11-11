N,K=map(int,input().split())
a=0
while N//K>=K:
  N=N//K
  a=a+1
print(a+2)