n, h, a, b, k = map(int, input().split())

for i in range(n):
  ta, fa, tb, fb = map(int, input().split())
  res = abs(ta-tb)
  if ta == tb:
    res += abs(fa-fb)
    print(res)
  else:
    if a <= fa and fa <= b:
      res += abs(fa-fb)
      print(res)
    else:
      if fa < a:
        res += abs(fb-a)+a-fa 
        print(res)
      else:
        res += abs(fb-b)+fa-b
        print(res)
