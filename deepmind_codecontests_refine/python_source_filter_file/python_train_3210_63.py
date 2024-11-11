a, b, k = map(int, input().split())
lst = list(range(a, b+1))
for i in sorted(set(lst[:k]) | set(lst[-k:])):
  print(i)