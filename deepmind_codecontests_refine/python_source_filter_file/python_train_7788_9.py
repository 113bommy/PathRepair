n = int(input())
v = list(map(int, input().split()))

odd = [[0, i] for i in range(10001)]
even = [[0, i] for i in range(10001)]

for i in range(0, n, 2):
  odd[v[i]][0] += 1
for i in range(1, n, 2):
  even[v[i]][0] += 1

odd.sort()
even.sort()

if odd[-1][1] != even[-1][1]:
  print(n - odd[-1][0] - even[-1][0])
else:
  print(n - max(odd[-2][0] + even[-1][0], odd[-1][0] + even[-2][0]))