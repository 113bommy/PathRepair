M, D = map(int, input().split())

cnt = 0
for i in range(20,D):
  d1 = i % 10
  d2 = i //10
  
  if 0 < d1*d2 <= M and d1>1 and d2>1:
#    print (i, d1*d2)
    cnt += 1

print (cnt)