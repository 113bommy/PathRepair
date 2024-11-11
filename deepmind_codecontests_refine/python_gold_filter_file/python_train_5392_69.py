
n=int(input())
s=input()
a=s[:n//2]
if s==a+a:
  print("Yes")
else:
  print("No")