S=input()[::-1]
ans,tmp=0,0
for i in S:
  if i=='W':
    tmp+=1
  else:
    ans+=tmp
print(ans)