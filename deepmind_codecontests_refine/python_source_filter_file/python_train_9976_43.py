x = int(input())
expo = set([1])
for b in range(2, x+1):
  v = b**2
  while v < x:
    expo.add(v)
    v *= b
print(max(expo))