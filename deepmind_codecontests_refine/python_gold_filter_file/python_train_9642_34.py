n = int(input())
string = input().lower()
sf, fs = 0, 0

for i in range(n-1):
  if string[i]+string[i+1] == "fs":
    fs += 1
  elif string[i]+string[i+1] == "sf":
    sf += 1

if sf > fs:
  print("YES")
else:
  print("NO")