N = int(input())
f = True
for h in range(1,3501):
  for n in range(1,3501):
    w_ = (-(h+n)/(h*n) + 4/N)
    if w_ > 0:
      w = (1/w_)
      if w%1 < 10E-6:
        print(h,n,int(w))
        f = False
        break
  if not f:
    break