n=int(input())
for i in range(n+1):
  if i*(i+1)//2>=n:break
ans=[]
for j in range(i,0,-1):
  if j<=n:
    n-=j
    ans+=[j]
print(*ans,sep='\n')