vals = [int(n) for n in input().split()]
n = vals[0]
x = vals[1]
start = 1
result = 0
for _ in range(n):
  moment = [int(n) for n in input().split()]
  result += ((moment[0]-start)%3) + moment[1] - moment[0] + 1
  start = moment[1]+1
print(result)
