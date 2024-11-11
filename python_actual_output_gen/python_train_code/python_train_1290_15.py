N,M = map(int,input().split())

prefec = [[] for _ in range(N)]

for i in range(M):
  p,y = map(int,input().split())
  prefec[p-1].append((y,i))

ans = [None]*M

for i,y in enumerate(prefec):
  y.sort()
  for k ,(y,j) in enumerate(y):
    ans[j] = "%06d%06d" %(i+1,k+1)
    
print(ans,end ='\n')