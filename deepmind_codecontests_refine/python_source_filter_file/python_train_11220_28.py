input()
l = list(map(int, input().split()))
res = 1
for x in l:
  res *= x
  if res > 10**18:
    print(-1)
    exit(0)
print(res)