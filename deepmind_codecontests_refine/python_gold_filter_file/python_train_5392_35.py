n = int(input())
s = input()
if s[:n//2] == s[n//2:n]:
  print("Yes")
else:
  print("No")