N = int(input())
a = list(map(int, input().split()))
res = [0] + a[:]
for i in range(N, 0, -1):
  res[i] = sum(res[i : : i]) % 2 
print(sum(res))
print(*[i for i in range(N) if res[i]])
