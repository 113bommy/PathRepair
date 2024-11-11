n = int(input())
s = input()
if s[0:n//2] == s[n//2:n]:
  print("yes")
else:
  print("no")