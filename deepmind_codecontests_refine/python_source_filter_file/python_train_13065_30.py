n,m=map(int,input().split())
cnt=0
for i in range(n):
  ls=list(map(int,input().split()))
  for j in range(0,m,2):
    if ls[j]==1 or ls[j+1]==1:cnt+=1
print(cnt) 
