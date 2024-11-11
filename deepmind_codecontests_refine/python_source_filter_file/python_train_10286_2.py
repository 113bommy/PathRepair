N=int(input())
p=list(map(int,input().split()))
count=0
for i in range(N):
  if p[i]!=i+1 :
    count+=1
if(count<=2):
  print("Yes")
else:
  print("No")