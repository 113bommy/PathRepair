import math

def on_one_line(x1, y1, x2, y2, x3, y3):
  result = x1 * y2 - y1 * x2 + y1 * x3 - x1 * y3 + x2 * y3 - x3 * y2;
  if result == 0:
    return True
  else:
    return False
    
n = int(input().strip())
node = []
for i in range(n):
  a, b = input().strip().split()
  node.append([int(a), int(b)])
  
mindis1 = 0
minidx1 = 0
for i in range(1, n):
  dis1 = math.sqrt(math.pow((node[i][0]-node[0][0]),2) + math.pow((node[i][1]-node[0][1]),2))
  if i == 1:
    mindis1 = dis1
    minidx1 = i
  elif dis1 < mindis1:
    mindis1 = dis1
    minidx1 = i

mindis2 = 10000000000000
minidx2 = 0 
for i in range(1, n):
  if on_one_line(node[0][0], node[0][1], node[minidx1][0], node[minidx1][1], node[i][0], node[i][1]) == False:
    dis2 = math.sqrt(math.pow((node[i][0]-node[minidx2][0]),2) + math.pow((node[i][1]-node[minidx2][1]),2))
    if dis2 < mindis2:
      mindis2 = dis2
      minidx2 = i


print("1 " + str(minidx1+1) + " " + str(minidx2+1))