n = int(input())
l = list(map(int, input().split()))
s = 0
for i in l:
  s = s^i
if s==0:
  print("Yes")
else:
  print("No")