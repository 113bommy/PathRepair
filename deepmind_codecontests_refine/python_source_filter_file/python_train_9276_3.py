stops = int(input())

valid = [0] * 101

for i in range(stops):
  arr = list(map(int, input().split(' ')))
  for u in range(1, len(arr)):
    valid[arr[u]] += 1

sol = []

for i in range(100):
  if(valid[i] == stops):
    sol.append(str(i))

print(' '.join(sol))
