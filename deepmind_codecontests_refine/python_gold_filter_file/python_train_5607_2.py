X,Y=map(int,input().split())
ans=10**10
for i in range(2):
  for j in range(2):
    x=(1-2*i)*X
    y=(1-2*j)*Y
    if x<=y:
      if ans>y-x+i+j:
        ans=y-x+i+j
print(ans)
