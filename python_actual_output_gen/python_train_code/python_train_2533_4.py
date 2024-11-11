k = int(input())
q = input()
b = []
for x in range(len(q)):
  if q[0: x + 1].count(q[x]) == 1:
    b.append(q[x])
  else:
    b[-1] += q[x]
if len(b) >= k:
  print("YES")
  for x in range(k-1):
    print(b[x])
  for y in range(k, len(b)):
    b[k-1] += b[y]
  print(b[k-1])
if len(b) <= k:
  print("NO")
  

