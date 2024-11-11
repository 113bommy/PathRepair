n,a,b=map(int,input().split())
s=input()
c,d=0,0
for i in range(n):
  if s[i]=="a":
    if c+1<=a+b:
      print("Yes")
      c+=1
    else:
      print("No")
  elif s[i]=="b":
    if c+1<=a+b and d+1<=b:
      print("Yes")
      c+=1
      d+=1
    else:
      print("No")
  else:
    print("No")