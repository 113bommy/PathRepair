N = int(input())
rate = [0] * 9
for a in [int(x) for x in input().split()]:
  rate[min(a, 3200) // 400] += 1

ret = 0
for r in rate[:-1]:
  if r:
    ret += 1

print(ret, ret + rate[-1])