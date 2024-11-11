n,a,b,c,d = map(int,input().split())
s = str(input())
if "##" in s[min(a,b):max(c,d)-1]:
  print("No")
  exit()
if d > c:
  if "..." in s[b-2:d+1]:
    print("Yes")
  else:
    print("No")
else:
  print("Yes")
