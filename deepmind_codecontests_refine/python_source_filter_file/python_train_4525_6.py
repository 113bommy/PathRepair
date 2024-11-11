class Pair:
  def __init__(self, id, difficult):
    self.id = id
    self.difficult = difficult
  def __lt__(self, other):
    return self.difficult < other.difficult

def printPair(pairs):
  tmp_a = []
  for i in range(len(pairs)):
    tmp_a.append(int(pairs[i].id) + 1)
  return " ".join(str(x) for x in tmp_a)

if __name__ == '__main__':
  try:
    n = int(input())
    a = list(map(int, input().split()))
    a_p = []

    for i in range(n):
      a_p.append(Pair(i, a[i]))
    a_p.sort()
    c = 0
    for i in range(n - 1):
      if a_p[i].difficult == a_p[i+1].difficult:
        c += 1
    if c == 2:
      print('YES')
      print(printPair(a_p))
      c = 0
      for j in range(n - 1):
        if a_p[j].difficult == a_p[j+1].difficult:
          c += 1
          a_p[j+1], a_p[j] = a_p[j], a_p[j+1]
          print(printPair(a_p))
          a_p[j], a_p[j+1] = a_p[j+1], a_p[j]
        if c == 2:
          break
    else:
      print('NO')

  except EOFError:
    sys.exit(0)
