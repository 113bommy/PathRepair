for e in iter(input,'0 0 0'):
 d=[2]*-~sum(map(int,e.split()))
 f=[]
 for _ in[0]*int(input()):
  s,t,u,v=map(int,input().split())
  if v:d[s]=d[t]=d[u]=1
  else:f+=[(s,t,u)]
 for s,t,u in f:
  if d[t]*d[u]!=1:d[s]=0
  if d[u]*d[s]!=1:d[t]=0
  if d[s]*d[t]!=1:d[u]=0
 print(d[1:],sep='\n')
