n = int(input())
stroy = input()
order = stroy[0]
wrong_r1 = 0
wrong_b1 = 0
wrong_b2 = 0
wrong_r2 = 0
for i in range(n):
  if i%2 == 0:
    if stroy[i] == 'b':
      wrong_b1 += 1
    else:
      wrong_r1 += 1
  else:
    if stroy[i] == 'b':
      wrong_b2 += 1
    else:
      wrong_r2 += 1
print(min(max(wrong_b1,wrong_r1),max(wrong_r2,wrong_b2)))