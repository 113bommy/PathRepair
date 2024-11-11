N, A, B = map(int, input().split())
ans = 0
for i in range(1, N+1):
  if A <= sum(map(int, list(str(i)))) <= B:
    ans += 1

print(ans)