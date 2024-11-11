n = int(input())
s = [int(input()) for _ in range(n)]

sumNum = sum(s)
if sumNum % 10 != 0:
  print(sumNum)
  exit()

t = 0
for i in s:
  if (sumNum - i)%10 != 0:
    t = max(t, sumNum-i)
print(t)