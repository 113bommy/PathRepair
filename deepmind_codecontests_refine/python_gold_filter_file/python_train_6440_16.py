n,a,b=map(int,input().split())
t=a+b
for s in list(input()):
  if str(s)=="a" and t>0:
    t-=1
    print("Yes")
  elif str(s)=="b" and t>0 and b>0:
    b-=1
    t-=1
    print("Yes")
  else:
    print("No")