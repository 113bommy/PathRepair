n=int(input())
a=[int(input()) for i in range(n)]

al= {}
ans=0
for ai in a:
  if ai - 1 in al.keys():
    al[ai]=al[ai-1]+1
    ans=max(ans,al[ai-1]+1)   
    del al[ai-1]
  else:
    al[ai]=1
    if ai + 1 in al.keys():
      del al[ai]
print(n-ans)