n,m=map(int, input().split())
s=[list(map(int, input().split())) for _ in range(n)]
c=[list(map(int, input().split())) for _ in range(m)]
for a,b in s:
  k=[]
  for c,d in c:
    k.append(abs(a-c)+abs(b-d))
  print(k.index(min(k))+1)