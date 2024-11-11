x, y = map(int, input().split())

l = []

if x <= y:
  l.append(y-x)
  
if -x <= y:
  l.append(y + x + 1)
  
if x <= -y:
  l.append(-y-x+1)
  
if -x <= -y:
  l.append(-y+x+2)
  
print(min(l))