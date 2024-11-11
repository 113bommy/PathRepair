a = input()
b = input()

pa = 0
pb = 0

wins = {'8': '[', '[': '(', '(': '8'}

for i in range(int(len(a)/2)):
  if b[2*i] == wins[a[2*i]]:
    pa += 1
  elif a[2*i] != b[2*i]:
    pb += 1

if pa > pb:
  print('TEAM 1 WINS');
if pa < pb:
  print('TEAM 2 WINS');
else:
  print('TIE');