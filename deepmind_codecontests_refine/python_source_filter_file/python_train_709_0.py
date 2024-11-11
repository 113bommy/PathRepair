n = int(input())
a = list(map(int, input().split()))
c4 = sum(1 for x in a if x % 4 == 0)
c1 = sum(1 for x in a if x % 2 == 1)
if c4 >= c1 or (c4 >= c1 - 1 and c4 + c1 == n):
  print("Yes")
else
  print("No")