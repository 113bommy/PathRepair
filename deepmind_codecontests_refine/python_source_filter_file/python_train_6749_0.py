n=int(input())
r=[list(map(int,input().split())) for i in range(n)]
b=[list(map(int,input().split())) for i in range(n)]
d,ans=dict(),0
for i in range(n):
  cnt=-1
  ok=False
  for j in range(n):
    if j not in d:
      if b[i][0]>r[j][0] and b[i][1]>r[j][1]:
        if r[j][1]>cnt:
          cnt=r[j][1]
          k=j
          ok=True
  if ok:
    ans+=1
    d[k]=0
print(ans)