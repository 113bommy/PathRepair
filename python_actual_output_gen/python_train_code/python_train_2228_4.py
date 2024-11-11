n,a,b=map(int,input().split());s=input();r,f=0,0
for i in range(n):
  if s[i]=="a":
    if r<a+b:
      print("Yes");r+=1
    else:print("No")
  elif s[i]=="b":
    if r<a+b and f<b:
      print("Yes");r+=1
    else:print("No");f+=1
  else:print("No")