n,a,b,c,d = map(int,input().split())
s = str(input())
if "##" in s[min(a,b)-1:max(c,d)]:
  print("No")
  exit()
if c > d:
  if "..." in s[b-1:d]:
    print("Yes")
  else:
    print("No")
else:
  print("Yes")
