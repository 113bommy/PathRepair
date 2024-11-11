n,d=map(int,input().split())
lis=[list(map(int,input().split())) for i in range(n)]
cnt=0
x=0
for i in range(n-1):
  for j in range(i+1,n):
    for k in range(d):
      x+=(lis[i][k]-lis[j][k])**2
    if (x**0.5).is_integer():
      cnt+=1
    x=0
print(cnt)