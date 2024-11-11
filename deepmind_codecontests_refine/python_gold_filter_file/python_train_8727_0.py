import sys
N=int(input())

for h in range(1,3501):
  for n in range(1,3501):
    bb=(4*h*n-N*n-N*h)
    bs=(N*h*n)
    if bb==0:
      continue

    if bs%bb==0 and 1<=bs//bb:
      print(h,n,bs//bb)
      sys.exit()