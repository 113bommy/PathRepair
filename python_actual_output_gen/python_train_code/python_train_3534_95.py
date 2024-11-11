a=int(input())
b,c=map(int,input().split())
if c-b>=c%a:
  print("Yes")
else:
  print("No")