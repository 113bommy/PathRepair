h,w,k=map(int,input().split())
c=[input() for _ in range(h)]
count=0
for H in range(h<<1):
  for W in range(W<<1):
    b=0
    for i in range(h):
      for j in range(w):
        if (W >> i) & 1 == 0 and (H >> j) & 1 == 0 and c[i][j] == "#":
          b+=1
    if b==k:
      count+=1
print(count)