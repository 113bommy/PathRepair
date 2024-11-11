#sm = 0
import sys
import math
num = int(input())
data = sys.stdin.readlines()
a = []
av = set()
for i in range(num):
    d = data[i] 
    if d[-5:] != "00000":
        a.append(math.floor(float(d)))
        av.add(i)
    else:
        a.append(int(d[:-6]))
    #sm += a[-1]

#print(a)
sm = -1 * sum(a)
for i in range(sm):
    ind = av.pop()
    a[ind] += 1
[print(q) for q in a]
