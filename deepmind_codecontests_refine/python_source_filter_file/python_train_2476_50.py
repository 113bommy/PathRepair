a,b,c,d=map(int,input().split())
x=int((a-1)/d)
y=int((c-1)/b)

if x>=y:
  print("yes")
else:
  print("no")