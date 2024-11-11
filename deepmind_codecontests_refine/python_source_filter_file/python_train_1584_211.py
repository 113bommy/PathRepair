from sys import stdin, stdout

def scal(typ=int):
  return typ(stdin.readline())

def vec(typ=int):
  if isinstance(typ, list):
    inp = stdin.readline().split()
    return [typ[i](inp[i]) for i in range(len(inp))]
  else:
    return list(map(typ, stdin.readline().split()))

n = scal()
if n % 2:
  print(n + 9, 9)
else:
  print(n + 2, 2)
