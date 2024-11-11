N = int(input())

ans = []
i = 1
while len(ans)<N:
  tmp = i*10 +1
  i += 1
  flag = 0
  for j in range(3, tmp//3+1):
    if tmp%j == 0:
      flag = 1
    break
  if flag == 0:
    ans.append(tmp)

for i in ans:
  print(i, end = " ")