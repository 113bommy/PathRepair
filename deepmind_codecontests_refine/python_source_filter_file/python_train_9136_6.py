import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

n = int(readline())
a = list(map(int,readline().split()))
s = a[0]+a[1]
if n == 2:
  if a[0] < a[1] or s%2 == 1:
    print(-1)
  else:
    print(a[0]-s//2)
  exit()
  
c = 0
for i in a[2:]:
  c ^= i

sc = (s-c)//2
if s < c or (s-c)%2 == 1 or c&sc:
  print(-1,0)
  exit()

bb = a[0].bit_length()
x = ''
chk = 0
for i in range(bb-1,-1,-1):
  if not (c>>i&1)|(sc>>i&1):
    x += '0'
  elif not c>>i&1 and sc>>i&1:
    x += '1'
    chk += 2**i
  else:
    x += '?'
  
for i in range(bb):
  if x[i] == '?':
    if a[0] >= chk+2**(bb-1-i):
      chk += 2**(bb-1-i)

ans = a[0]-chk
print(ans if a[0] > ans > 0 else -1)