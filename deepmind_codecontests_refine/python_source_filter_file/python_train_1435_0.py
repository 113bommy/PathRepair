N,M=map(int,input().split())
l=[set() for i in range(N)]
for i in range(M):
  a,b=map(int,input().split())
  l[a-1].add(b-1)
  l[b-1].add(a-1)
ope=[1]*N
ope[0]=0
s={0}
ans=[-1]*N
while len(s):
  news=set()
  for j in s:
    for k in l[j]:
      if ope[k]:
        news.add(k)
        ans[k]=j
        ope[k]=0
  s=news
print('yes')
for i in range(1,N):
  print(ans[i]+1)
    