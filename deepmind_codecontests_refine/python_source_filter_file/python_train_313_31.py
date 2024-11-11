import sys
for l in sys.stdin:
  H, W = map(int,l.split())
  if H == 0 and W == 0:
    break
  for i,h in enumerate(range(H)):
    if i % 2 == 0:
      print (('.#' * (int(W/2)))[:W])
    else:
      print(('#.' * (int(W/2)))[:W])
  print ('')