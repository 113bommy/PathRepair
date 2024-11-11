n=int(input())
for i in range(n):
  a,b=map(int,input().split())
  if a==b:
    ct+=1
    if ct==3:
      print("Yes")
      break
  else:
    ct==0
else:
  print("No")