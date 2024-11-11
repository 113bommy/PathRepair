c1=0
c2=0
for _ in range(int(input())):
  n,k=map(int,input().split())
  if n>k:
    c1+=1
  elif n<k:
    c2+=1
if c1==c2:
    print("Friendship is magic!^^")
elif c1>c2:
  print("Mishika")
else:
    print("Chris")

