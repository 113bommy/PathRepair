n = int(input())
table = [[] for _ in range(n+1)]
for i in range(1, n+1):
  a = list(map(int, input().split()))
  table[i] = a
cursor = [0]*(n+1)
is_matched = set()
d = 0
match = 0
while match < n * (n-1) //2:
  now_match = match
  for i in range(1, n):
    if cursor[i] < n-1 and i not in is_matched:
      j = table[i][cursor[i]]
      if i < j and j not in is_matched and table[j][cursor[j]] == i :
        match += 1
        cursor[i] += 1
        is_matched.add(i)
        cursor[j] += 1
        is_matched.add(j)
  if now_match == match:
    print(-1)
    exit()
  if d > 300000:
    print(499500)
    exit()  
  d += 1
  is_matched.clear()
print(d)