M,D = map(int,input().split())
count = 0
for i in range(D):
  if i%10 >= 2 and i//10 >= 2:
    if (i%10) * (i//10) <= M:
      count += 1
print(count)