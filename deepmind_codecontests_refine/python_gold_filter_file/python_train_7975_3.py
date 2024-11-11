from sys import stdin

n = int(stdin.readline())

items = []

for i in range(n):
  t,d,p = [int(x) for x in stdin.readline().split()]
  items.append((d,t,p,i))

items.sort()

mem = [{} for x in range(n)]
mem2 = [{} for x in range(n)]

def best(time,x):
  time += items[x][1]
  if time in mem[x]:
    return mem[x][time]

  if time >= items[x][0]:
    mem[x][time] = 0
    mem2[x][time] = -1
    return 0
  
  top = 0
  top2 = -1

  for i in range(x+1,n):
    temp = best(time,i)
    if temp > top:
      top = temp
      top2 = i

  mem[x][time] = top+items[x][2]
  mem2[x][time] = top2
  return mem[x][time]

top = -1
l = []

for x in range(n):
  b = best(0,x)
  if b > top:
    top = b
    #print('new',x,top)
    l = []
    c = x
    time = 0
    while c != -1:
      time += items[c][1]
      l.append(items[c][3])
      if time in mem2[c]:
        c = mem2[c][time]
      else:
        c = -1

print(top)
if top != 0:
  print(len(l))
  print(' '.join([str(x+1) for x in l]))
else:
  print(0)
  print()
    
