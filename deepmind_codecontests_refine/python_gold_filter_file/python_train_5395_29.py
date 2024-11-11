n=int(input())
ans=0
l=[105,135,165,189,195]
for i in range(n+1):
  if i in l:
    ans+=1
print(ans)