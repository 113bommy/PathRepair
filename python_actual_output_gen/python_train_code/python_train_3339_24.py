n = int(input())
di = {}

for x in range(n):
  i = int(input())
  if (i in di.keys()):
    di.pop()
  else:
    di[i] = i
print(len(di))