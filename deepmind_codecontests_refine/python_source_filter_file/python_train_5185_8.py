N,D=map(int,input().split())
L=[]
hei=[i**2 for i in range(70)]

for i in range(N):
  l=list(map(int,input().split()))
  L.append(l)
ans=0
for i in range(N):
  for j in range(i+1,N):
    if sum((L[i][k]-L[j][k])**2 for k in range(D)) in hei:
      ans+=1
print(ans)