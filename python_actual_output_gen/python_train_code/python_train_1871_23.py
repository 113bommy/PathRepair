n = int(input())
a = input()
if a[:n/2+1]==a[n/2+1:]:
  print("Yes")
else:
  print("No")