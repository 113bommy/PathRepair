import sys
 
def readInt():
  return int( rl() )
 
def readList():
  return list(map(int, rl().strip().split()))
 
def readStr():
  return rl().strip()
 
def makeMatrix(a, b, value):
  z = [value]*a
  for i in range(a):
    z[i] = [value]*b
  return z

INF = 100500
 
rl = input
n, h, l, r = readList()
a = readList()

t = [-INF]*h
t[0] = 0

for x in a:
  #print("x=%i" % (x))
  nt = [-INF]*h
  for i in range(h):
    j = (i + x) % h
    d = 0
    if l <= j <= r: d = 1
    nt[j] = max(nt[j], t[i] + d)


    j = (i + x - 1) % h
    d = 0
    if l <= j <= r: d = 1
    nt[j] = max(nt[j], t[i] + d)

  #print(t)
  #print(nt)
  #print("")

  t = nt[:]

print(max(t))