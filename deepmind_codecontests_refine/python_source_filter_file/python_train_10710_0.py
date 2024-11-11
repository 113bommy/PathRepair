def judge(h, hset):
  rest = hset - {h}
  if len(rest) in (0, 2):
    return 3
  if (h + 1) % 3 in rest:
    return 1
  else:
    return 2

while True:
  h1 = int(input())
  if h1 == 0:
    break
  hlst = []
  hset = set()
  hlst.append(h1)
  hset.add(h1)
  for _ in range(4):
    h = int(input())
    hlst.append(h)
    hset.add(h)
  for h in hlst:
    print(judge(h, hset))


