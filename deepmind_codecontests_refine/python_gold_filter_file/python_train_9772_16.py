s=set(input())
if len(s)%2==0:
  if s==set("SN") or s==set("WE") or s==set("SENW"):
    print("Yes")
  else:
    print("No")
else:
  print("No")