n, m = map(int, input().split())
s = set(str(i) for i in range(1, m+1))
for _ in range(n):
  s = s & set(input().split()[1:])
print(len(s))