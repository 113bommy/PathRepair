n = int(input())
day =0

for i in range(n):
  s,d = input().strip().split()
  s = int(s)
  d = int(d)
  if i==0:
    day = s
  else:
    if s > day:
      day =s
    else:
      day = s + (1+(day -s)//d) * d
print(day)