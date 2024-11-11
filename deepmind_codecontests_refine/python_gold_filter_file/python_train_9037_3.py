N = int(input())

start = int(input())
flag = 0
if start != 0:
 flag = 1
t = 0

for i in range(N-1):
 k = int(input())
 if k == start:
  t += start
 elif k == start + 1:
  t += 1
  start = k
 elif k == 0:
  start = 0
 elif k > start + 1:
  t = -1
  break
 else:
  t += k
  start = k

if flag ==1:
 t = -1
print(t)