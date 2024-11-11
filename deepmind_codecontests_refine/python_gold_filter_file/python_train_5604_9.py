N = int(input())
ans = list()
flag = [0] * 55556
flag[1] = 1
for i in range(1, 55556):
  if(flag[i] == 0):
    if(i%5 == 1):
      ans.append(i)
    p = i
    while(p <= 55555):
      flag[p] = 1
      p += i
print(*ans[:N])