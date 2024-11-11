n=int(input())
m=n//2*2
ans=[]
for i in range(1,m//2):
  for j in range(1+i,m-i+1):
    ans.append((i,j))
    ans.append((n-j,n-i))
if n%2:
  for i in range(1,n):
    ans.append((i,n))
print(len(ans))
for i in ans:
  print(*i,sep=" ")