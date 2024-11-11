n,m = map(int,input().split())
l_n =list(list(map(int,input().split())) for i in range(n))
l_m =list(list(map(int,input().split())) for i in range(m))
for i in range(n):
  q = 10**9
  for t in range(m):
    a,b = l_n[i]
    c,d = l_m[t]
    v= abs(a-c)+abs(b-d)
    if v<q:
      q = v
      z = t
  print(z+1)