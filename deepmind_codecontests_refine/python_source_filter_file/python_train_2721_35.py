n = int(input())
arr = list(map(int, input().split()))
pos, neg = 0, 0

for i in range(n):
  if arr[i] > 0:
    pos += 1
  elif arr[i] < 0:
    neg += 1

if n % 2 != 0:
  half = (n//2) + 1
else:
  half = n//2

if half > max(pos, neg):
  print(0)
if max(pos, neg) == neg:
  print(-1)
else:
  print(2)