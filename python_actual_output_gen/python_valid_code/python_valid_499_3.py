class io:
  s = input
  i = lambda: int(io.s())
  f = lambda: float(io.s())
  ts = lambda: io.s().split()
  ti = lambda: map(int, io.ts())
  tf = lambda: map(float, io.ts())
  ls = lambda: list(io.ts())
  li = lambda: list(io.ti())
  lf = lambda: list(io.tf())

for _ in range(int(input())):
  n, m, rb, cb, rd, cd = io.li()

  cnt = 0
  dr = dc = 1
  while rb != rd and cb != cd:
    if rb + dr < 1 or rb + dr > n: dr = -dr
    if cb + dr < 1 or cb + dr > m: dc = -dc
    rb += dr
    cb += dc
    cnt += 1

    # if cnt > 10: break
    # print((rb, cb), (rd, cd))

  print(cnt)
