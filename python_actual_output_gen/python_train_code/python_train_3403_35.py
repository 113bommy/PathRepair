N, A, B = list(map(int, input().split()))
res = 0
for i in range(N+1):
  if A <= sum([int(s) for s in str(i)]) <=B:
    res += 1
print(res)