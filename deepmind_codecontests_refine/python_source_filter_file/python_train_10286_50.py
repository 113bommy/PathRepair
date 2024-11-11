n=int(input())
li=list(map(int,input().split()))
a=0
for i in range(n):
  if li[i]==i+1:
    a+=1
if a==2:
  print("YES")
else:
  print("NO")