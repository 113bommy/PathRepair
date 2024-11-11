N = int(input())
ans = 0
for i in range(1,35):
  for k in range(2,10):
    if i**k <= N and i**k >= ans:
      ans = i**k
print(ans)