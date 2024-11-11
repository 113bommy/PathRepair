a = [ int(x) for x in input()]
b = sorted([ int(y) for y in input()], reverse=True)
y = 0

for i in range(0, len(a) ):
  if y < len(b) - 2 and a[i] < b[y] :
    a[i] = b[y]
    y = y + 1



print("".join([str(c) for c in a]))