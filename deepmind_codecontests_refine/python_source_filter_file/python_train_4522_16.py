origin = input()
target = input()

def char2Num(c):
  return ord(c)-ord('a')+1

def num2Char(d):
  return chr(ord('a')+d-1)

x_origin = char2Num(origin[0])
y_origin = int(origin[1])

x_target = char2Num(target[0])
y_target = int(target[1])

x = x_origin
y = y_origin
steps = []

while x < x_target and y < y_target: # keep RU until x reaches x_target or y reaches y_target
  steps.append('RU')
  x += 1
  y += 1
while x<x_target and y > y_target:
  steps.append('RD')
  x += 1
  y -= 1
while x > x_target and y < y_target: 
  steps.append('LU')
  x -= 1
  y += 1
while x>x_target and y > y_target:
  steps.append('LD')
  x -= 1
  y -= 1
while x < x_target:
  steps.append('R')  
  x += 1
while x < x_target:
  steps.append('L')  
  x -= 1
while y < y_target:
  steps.append('U')
  y += 1
while y > y_target:
  steps.append('D')
  y -= 1  
print(len(steps))
for step in steps:
  print(step)