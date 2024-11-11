N, M = map(int, input().split())

all_set = set.intersection(*map(set, (
  list(map(int, input().split()))[1:]
  for i in range(N)
))

print(len(all_set))