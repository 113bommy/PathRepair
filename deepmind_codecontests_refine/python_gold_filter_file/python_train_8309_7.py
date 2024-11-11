n,q = map(int, input().split())
if n == 1:
  for _ in range(q):
    print(min(map(int, input().split())))
else:
  for _ in range(q):
    v,w = map(int, input().split())
    while v != w:
      if v > w:
        v,w = w,v
      w = (w+n-2)//n
    print(v)