def main():
  N,P = map(int,input().split())
  n0 = 0
  n1 = 0
  for a in map(int,input().split()):
    if a%2 == 0:
      n0 += 1
    else:
      n1 += 1
  if P == 1 and n1 == 0:
    print(0)
    return
  print(2**(n0+n1-1))

main()