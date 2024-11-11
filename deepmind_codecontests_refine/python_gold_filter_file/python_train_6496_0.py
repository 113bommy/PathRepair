N, M = map(int, input().split())

A = list(map(int, input().split()))

s = 0
count = 0
for a in A:
  # print(s + 1, a, ( (a - 1) - s + N )%N)
  count += ( (a - 1) - s + N )%N
  s = (a - 1)
print(count)