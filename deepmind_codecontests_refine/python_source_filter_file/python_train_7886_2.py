n,m=map(int,input().split())

global fri
fri=[]
global tab
tab=[0]*n
def run(nn):
  #print(tab)
  global cnt
  if tab[nn]:
    return
  tab[nn]=1
  cnt+=1
  for i in fri[nn]:
    que.append(i)
for i in range(n):
  fri.append([])
for i in range(m):
  a,b=map(int,input().split())
  fri[a-1].append(b-1)
  fri[b-1].append(a-1)
i=0
mx=0
cc=0
while i<n:
  if tab[i]:
    i+=1
    continue
  que=[i]
  cnt=0
  while len(que)!=0:
    run(que.pop())
  mx=max(cnt,mx)
  i+=1
  cc+=1
print(cc)

