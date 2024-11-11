N=input()
n=int(N)
x=0
for s in range(n):
  ds1,ds2=input().split()
  if ds1==ds2:
    x+=1
  else:
    x==0
  if x==3:
    print("Yes")
    break
else:
  print("No")
