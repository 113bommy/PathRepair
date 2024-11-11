import sys

bt = 0
num = 0

for line in sys.stdin:
  if line[0] == '+':
    num += 1
  elif line[0] == '-':
    num -= 1
  else:
    bt += num*(len(line) - line.index(':') - 1)

print(bt)