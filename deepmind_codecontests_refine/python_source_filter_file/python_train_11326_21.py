h, w, a, b = map(int, input().split())

for i in range(h):
  for j in range(w):
    print( 1 if (i<a)^(j<b) else 0, end = "" )
  print()