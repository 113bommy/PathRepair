n,a,b,c,d=map(int,input().split())
s=input()
if "##" in s[min(a,b)-1:max(c,d)]:
  print("No")
else:
  if c<d:
    print("Yes")
  else:
    if "..." in s[a-1:d+2]:
      print("Yes")
    else:
      print("No")
        
