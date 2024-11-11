num = int(input())
xpos = 0
xneg = 0
S1='X++'
S2='X--'
S3='--X'
S4='X++'
for i in range(num):
  userinput = input()
  if userinput == S2:
    xneg = xneg -1
  elif userinput == S1:
    xpos = xpos + 1
  elif userinput == S3:
    xpos = xpos - 1
  elif userinput == S4:
    xpos = xpos + 1
  

res = xpos + xneg


print(res)
