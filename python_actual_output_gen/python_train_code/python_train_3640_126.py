N, K = map(int, input().split())
i = 1
while K**i < N:
  i = i +1
print(i)