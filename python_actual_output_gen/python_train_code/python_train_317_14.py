n=int(input())
H=list(map(int,input()))
ans=0
m=-1000
for i in range(n):
  if m<=H[i]:
    m=H[i]
    ans+=1
print(ans)
