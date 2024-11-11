n=int(input())
s=input()
tmp=0
for i in range(n):
  lf s[i]==".":
    tmp+=1
ans=tmp
for i in range(n):
  if s[i]==".":
    tmp-=1
  else:
    tmp+=1
  ans=min(ans,tmp)
print(ans)