d,g = map(int,input().split())
pc = []
m = 0
for i in range(d):
  pc.append(list(map(int,input().split())))
  m += pc[-1][0]
for i in range(2**d-1):
  cur = bin(i)[2:]
  cur = '0'*(d-len(cur)) + cur
  csum = 0
  cc = 0
  for j in range(d):
    if cur[j] == '0':
      ci = j
    else:
      csum += (j+1)*100*pc[j][0] + pc[j][1]
      cc += pc[j][0]
  if csum >= g:
    m = min(m,cc)
  elif csum + (ci+1) * 100 * pc[ci][0] >= g:
      m = min(m,cc+(g-csum-1)//(100*(ci+1))+1)
print(m)