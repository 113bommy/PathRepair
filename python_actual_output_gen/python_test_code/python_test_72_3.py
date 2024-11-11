N,M = map(int,input().split())
a = 0
w = 0
lis = [[] for i in range(N)]
for i in range(M):
  p,s = map(int,input().split())
  p = int(p)
  lis[p - 1].append(s)
for j in range(N):
  if lis[j].count("AC") > 0:
    a += 1
    w += lis[j].index("AC")

    
print(a,w)

