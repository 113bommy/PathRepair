n=input()
p=list(map(int,input().split()))
cnt=0
for i in range(len(p)):
  if(p[i]!=i):
    cnt+=1

if(cnt<=2):
  print("YES")
else:
  print("NO")