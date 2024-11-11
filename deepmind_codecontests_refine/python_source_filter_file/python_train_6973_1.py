a = int(input())

aa = 0

un = 0

p = 0

for i in range(a):
  k = input()
  if k == 'A':
    aa += 1
  elif k == 'Un':
    un += 1
  if un > aa:
    p = 1

if aa > un:
  p = 1
  
if p = 0:
  print("YES")
else:
  print("NO")
