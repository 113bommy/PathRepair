f = lambda x: x if p[x]<0 else f(p[x])
N,M = map(int,input().split())
p = [-1]*N
for _ in range(M):
  A,B = map(lambda x:f(int(x)),input().split())
  if A==B: continue
  elif A<B: A,B=B,A
  p[A] += p[B]
  p[B] = A
print(sum(i<0 for i in p)-1)