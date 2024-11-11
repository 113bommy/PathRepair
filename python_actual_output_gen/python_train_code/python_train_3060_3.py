def solve():
  a, b = [int(x) for x in input().split()]
  print(int((b * (b - 1) / 2) * (a * (a + 1) * b / 2 + a) % (1e9 + 7)))

if __name__ == '__main__':
  solve()
