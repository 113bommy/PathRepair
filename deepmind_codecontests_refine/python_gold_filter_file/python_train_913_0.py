N=int(input())
V=list(map(int,input().split()))
V.sort()
v=V[0]
for i in range(1,len(V)):
  v=(v+V[i])/2
print(v)