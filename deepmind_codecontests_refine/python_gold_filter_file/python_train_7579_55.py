n,k=map(int,input().split())
h=[int(input()) for i in range(n)]
h=sorted(h)
l=[]
for j in range(n-k+1):
  l.append(h[j+k-1]-h[j])
print(min(l))