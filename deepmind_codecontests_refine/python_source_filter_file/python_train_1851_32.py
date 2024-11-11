n,d=list(map(int,input().split()))
cnt=0
for i in range(n):
  x,y=list(map(int,input().split()))
  if (x**2+y**2)==d**2:
    cnt+=1
print(cnt)
  