a=int(input())
d=[]
t=0
g=0
h=map(int,input().split())
for i in range(a-1):
  if h[i]>=h[i+1]:
    g+=1
  else:
    d.append(g)
    g=0
d.append(g)
print(max(d))