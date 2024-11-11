N,M=list(map(int,input().split()))
ans=0
for u in range(N):
  a,b=map(int,input().split())
  S=a*a+b*b
  if M*M<=S:
    ans+=1
print(ans)