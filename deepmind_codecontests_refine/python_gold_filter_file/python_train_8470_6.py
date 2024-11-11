y = int(input())

for i in range(y+1, y*y):
  s = str(i)
  if len(set(s)) == len(s):
    print(i)
    break
