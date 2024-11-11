#"1"の座標を、最初のものを(0,0)として切り出し
def trim(mp):
  ret = []

  for x in range(8):
    for y in range(8):
      if mp[y][x] == "1":
        if not ret:
          refer = (x, y)
        ret.append((x, y))

  ret = [(x - refer[0], y - refer[1]) for x, y in ret]
  return ret

#座標が一致したものを出力
def put_ans(points):
  if points == [(0, 0), (0, 1), (1, 0), (1, 1)]: print("A")
  if points == [(0, 0), (0, 1), (0, 2), (0, 3)]: print("B")
  if points == [(0, 0), (1, 0), (2, 0), (3, 0)]: print("C")
  if points == [(0, 0), (0, 1), (1, 0), (1, -1)]: print("D")
  if points == [(0, 0), (1, 0), (1, 1), (2, 1)]: print("E")
  if points == [(0, 0), (0, 1), (1, 1), (1, 2)]: print("F")
  if points == [(0, 0), (1, -1), (1, 0), (2, -1)]: print("G")

while True:
  mp = [input() for _ in range(8)]
  put_ans(trim(mp))
  try:
    input()
  except EOFError:
    break
