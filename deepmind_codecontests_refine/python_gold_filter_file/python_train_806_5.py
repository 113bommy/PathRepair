N = input()
A = map(int, input().split())
sum = 0
pre = 0
for ai in A:
  if pre > ai:
    sum += pre - ai
  else:
    pre = ai
print(sum)