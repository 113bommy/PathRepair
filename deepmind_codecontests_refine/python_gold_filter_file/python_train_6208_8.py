a = list(map(int, input().split()))

sum_to_make = sum(a) / 2

flag = 0
l = len(a)
for i in range(l):
  for j in range(i+1,l):
    for k in a[j+1:]:
      if a[i]+a[j]+k == sum_to_make:
        print('YES')
        flag = 1
        break
    if flag == 1:
      break
  if flag == 1:
    break

if flag == 0:
  print('NO')
