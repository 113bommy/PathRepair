s = input()
t = input()

def Char2Num(ch):
  return ord(ch) - ord('a') + 1   # using offset to make 'A' to 1

def Num2Char(num):
  # return str(num)   # does this work?
  return chr(ord('a')+num-1)  # chr and ord are reverse

s_x = Char2Num(s[0]) 
s_y = int(s[1])

t_x = Char2Num(t[0])
t_y = int(t[1])

steps = []  # initialize the steps as empty list

x = s_x
y = s_y
while x<t_x and y<t_y: # if t is right upper RU
  steps.append("RU")
  x += 1
  y += 1
while x < t_x and y < t_y: # if t is left down LD
  steps.append("LD")
  x -= 1
  y -= 1
while x<t_x and y >t_y: # if t is right down, RD
  steps.append("RD")
  x += 1
  y -= 1
while x>t_x and y<t_y:  # if t is left up, LU
  steps.append("LU")
  x -= 1
  y += 1
while x<t_x:  # because we execute diagonal first, means either x is at the target, or y is at the target
  steps.append("R")
  x += 1
while x > t_x:
  steps.append("L")
  x -= 1
while y < t_y:
  steps.append("U")
  y += 1
while y > t_y:
  steps.append("D")
  y -= 1

print(len(steps))
for step in steps:
  print(step)
