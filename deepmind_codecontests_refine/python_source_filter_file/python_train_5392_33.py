n = int(input())
s = input()

if(s[:n/2-1] == s[n/2:]):
  print("Yes")
else:
  print("No")
