n,k=map(int,input().split())
h=[input() for _ in range(n)]
h=sorted(h)
l=[]
for i in range(n-k+1):
  l.append(h[i+k-1]-h[i])
print(min(l))