a, b, c , x = [int(input()) i for range(4)]
n = 0
for i in range(a+1):
  for j in range(b+1):
    for k in range(c+1):
      if i*500 + j*100 + k*50 == x:
        n += 1
print(n)


