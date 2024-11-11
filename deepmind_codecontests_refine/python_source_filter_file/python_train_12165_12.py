n,k=map(int,input().split())
B=[0]*100001

for i in range(1,n+1):
  a,b=map(int,input().split())
  B[a]+=b
for j in range(1,n+1):
  k-=B[j]
  if k<=0:
    print(j)
    break
