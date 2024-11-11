N,M,K=map(int,input().split())
ans="No"
for x in range(N+1):
  a=K-x*M
  b=N-2*x
  if x!=0 and a%b==0 and 0<=a//b<M:
    print("Yes")
    exit()
print("No")