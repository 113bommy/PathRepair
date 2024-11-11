m = int(input())
csum = 0
dsum = 0
for i in range(m):
  d,c = (int(x) for x in input().split())
  csum += c
  dsum += d*c
print(csum-1 + dsum // 9)
