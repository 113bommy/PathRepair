n,a,b,c=map(int,input().split())
l=[int(input()) for _ in range(n)]
ans=10**18
for i in range(4**n):
  la,lb,lc,ca,cb,cc=0,0,0,0,0,0
  for j in range(n):
    if (i>>2*j)&1 and not (i>>2*j+1)&1:
      ca+=1
      la+=l[j]
    if not (i>>2*j)&1 and (i>>2*j+1)&1:
      cb+=1
      lb+=l[j]
    if (i>>2*j)&1 and (i>>2*j+1)&1:
      cc+=1
      lc+=l[j]
  if ca*cb*cc:ans=min((ca+cb+cc-3)*10+abs(la-a)+abs(lb-b)+abs(lc-c),ans)
print(ans)