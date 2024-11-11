h,w,k=map(int,input().split())
c=[input() for _ in range(h)]
count=0
for H in range(1<<h):
  for W in range(1<<w):
    b=0
    for i in range(h):
      for j in range(w):
        if (H >> i) & 1 == 0 and (W >> j) & 1 == 0 and c[i][j] == "#":
          b+=1
    if b==k:
      count+=1
print(count)