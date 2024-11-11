from bisect import*
s=input()
t=input()
n=len(s)
d=dict(zip([chr(i+97) for i in range(26)],[[] for _ in range(26)]))
for i,j in enumerate(s,1):
  d[j]+=[i]
ans=0
cnt=0
for i in t:
  if d[i]:
    j=bisect(d[i],ans)
    if j==len(d[i]):
      cnt+=1
      ans=d[i][0]
    else:ans=d[i][j]
  else:
    cnt,ans=0,-1
    break
print(cnt*n+ans)