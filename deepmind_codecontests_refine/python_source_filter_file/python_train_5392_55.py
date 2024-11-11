n = int(input())
s = input()
if s == s[:n//2+1]*2:
  print("Yes")
else:
  print("No")