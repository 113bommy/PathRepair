n = int(input())
l = list(map(int,input().split()))
ans = 0
for i in range(n):
  ans^l[i]
if ans == 0:
  print("Yes")
else:
  print("No")