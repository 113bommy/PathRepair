from heapq import*
def g(n,E,s,g):
 F=[1e7]*-~n;F[s]=0
 H=[(0,s)]
 while H:
  c,u=heappop(H)
  if u==g:return c
  for f,v in E[u]:
   t=c+f
   if t<F[v]:F[v]=t;heappush(H,(t,v))
 return-1
def s():
 for e in iter(input,'0 0'):
  n,k=map(int,e.split())
  E=[[]for _ in[0]*-~n]
  for _ in[0]*k:
   f=[*map(int,input().split())]
   if f[0]:
    c,d,e=f[1:]
    E[c]+=[(e,d)];E[d]+=[(e,c)]
   else:print(g(n,E,*f[1:]))
if'__main__'==__name__:s()
