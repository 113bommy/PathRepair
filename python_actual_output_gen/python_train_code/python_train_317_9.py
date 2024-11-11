N = int(input())
l = list(map(int, input().split()))

th = 0
ans = 0
for x in l:
  if x >= th:
    ans += 1
  th = x
print(ans)