n, k = map(int, input().split())
mes = list(map(int, input().split()))
ss = [0] * n
def calc(start):
  last = n
  cur = start
  s = 0
  while (cur != 0) and (last > 0):
    if cur <= last:
      s += 1
      s += min(k, cur - 1)
      s += min(k, last - cur)
    else:
      s += max(last - (cur - min(k, cur - 1) - 1), 0)
    
    last = cur - min(k, cur - 1) - 1
    cur = mes[cur - 1]

    if ss[cur - 1] != 0:
      s += max(ss[cur - 1] - max(min(cur + k, n) - last, 0), 0)
      break
    
  ss[start - 1] = s
  return s
    
for i in range(1, len(mes)):
  print(calc(i), end=' ')
print(calc(len(mes)))