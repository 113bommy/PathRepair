s=list(input())
n=len(s)
r,c=0,0
ans=0
for i in range(n):
  r+=int(s[i])
  c+=1
  if int(s[i])==0 or r%3==0 or c==3:
    ans+=1
    r=c=0
print(ans)