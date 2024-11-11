N =int(input())
s = input()

if s[:N//2] == s[N//2:]:
  print("Yes")
else:
  print("No")