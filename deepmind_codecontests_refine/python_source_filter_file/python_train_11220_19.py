n = int(input())
a = list(map(int, input().split()))

ans = 1
for x in a:
  ans *= x
  if ans > (10 ** 18):
    ans = -1
    break
print(ans)
