import sys
N = int(input())
for i in range(1,3501):
  for j in range(max(i-1,1),3501):
    if (4*i*j - N*i -N*j) != 0:
      w = (N*i*j)/(4*i*j - N*i -N*j)
      if w > 0 and w.is_integer():
        print(i,j,int(w))
        sys.exit()