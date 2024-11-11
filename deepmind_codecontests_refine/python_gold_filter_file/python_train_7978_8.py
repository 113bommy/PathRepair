n = input()
s = input()
x = 0
y = 0
x1 = [0,0,0]
y1 = [0,0,0]
x2 = [[],[],[]]
y2 = [[],[],[]]
c = 0


for e in range(0,len(s)):
  if s[e] == "R":
    x += 1
    x1.append(x)
    x1.pop(0)

    y2.pop(0)
    y2.append([])
    for i in y1:   
      y2[2].append(i)

    x2.pop(0)
    x2.append([])
    for i in x1:   
      x2[2].append(i)
  
  else:
    y +=1
    y1.append(y)
    y1.pop(0)

    x2.pop(0)
    x2.append([])
    for i in x1:   
      x2[2].append(i)

    y2.pop(0)
    y2.append([])
    for i in y1:   
      y2[2].append(i)
  #EJE Y
  if x2[0] == x2[1] and x2[1] == x2[2] and x2[0] != []:
    if y2[0][2]+1 == y2[1][2] and y2[1][2] == y2[2][2]-1:
      if x == y-1:
        c+=1
  #EJE X
  if y2[0] == y2[1] and y2[1] == y2[2] and y2[0] != []:
    if x2[0][2]+1 == x2[1][2] and x2[1][2] == x2[2][2]-1:
      if y == x-1:
        c+=1
print(c)