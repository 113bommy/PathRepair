a = int(input())
k = a
for i  in range(a+1):
  al = 0
  t = i
  while t > 0:
    al += t%6
    t //=6
  t = a - i
  while t > 0:
    al += t%9
    t //=9
  if al < k:
    k = al

print(al)
