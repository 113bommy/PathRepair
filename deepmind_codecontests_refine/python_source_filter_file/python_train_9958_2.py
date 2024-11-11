n, m = list(map(int, input().split()))
x = list(map(int, input().split()))
y = list(map(int, input().split()))
filesCnt = 0

xs = 0
ys = 0

xcnt = 0
ycnt = 0

while n >= xcnt or m >= ycnt:
  print(xs, ys)
  if xs == ys and xs != 0:
    filesCnt += 1
    xs = 0
    ys = 0
    if n > xcnt or m > ycnt:
      continue
    else:
      break

  else:
    if xs > ys:
      ys += y[ycnt]
      ycnt += 1
    else:
      xs += x[xcnt]
      xcnt += 1

print(filesCnt)