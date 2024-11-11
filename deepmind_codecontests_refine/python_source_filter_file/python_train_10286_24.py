N = int(input())
p = list(map(int,input().split()))
num = 0
for i in range(N):
  if(p[i]!=i+1):
    num+=1
if(num>2):
  print("No")
else:
  print("Yes")