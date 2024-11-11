L, R = map(int, input().split())
if R-L >= 4050:
  print(1)
else:
  m = 2020
  for i in range(L, R):
    for j in range(i+1,R+1):
      m = min(m, (i*j)%2019)
print(m)