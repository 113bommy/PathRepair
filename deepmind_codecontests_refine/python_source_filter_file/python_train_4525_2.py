import sys
import math
  
n = int(sys.stdin.readline())
hn = [int(x) for x in (sys.stdin.readline()).split()]

a = []
b = []
c = []

d = dict()
for i in range(n):
    if hn[i] in d:
        d[hn[i]].append(i + 1)
    else:
        d[hn[i]] = [i + 1]
    
y = list(d.keys())
y.sort()

f = 0
for i in y:
    if(len(d[i]) > 2):
        k = d[i]
        a.append(k[0])
        a.append(k[1])
        a.append(k[2])
        a.extend((k[3:]))
        b.append(k[1])
        b.append(k[0])
        b.append(k[2])
        b.extend((k[3:]))
        c.append(k[2])
        c.append(k[1])
        c.append(k[0])
        c.extend((k[3:]))
        f += 1
    elif(len(d[i]) == 2):
        k = d[i]
        if(f % 2 != 0):
            a.append(k[0])
            a.append(k[1])
            b.append(k[1])
            b.append(k[0])
            c.append(k[0])
            c.append(k[1])
        else:
            a.append(k[0])
            a.append(k[1])
            b.append(k[1])
            b.append(k[0])
            c.append(k[0])
            c.append(k[1])
            
        f += 1
    else:
        a.append(d[i][0])
        b.append(d[i][0])
        c.append(d[i][0])

if(f > 1):
    print("YES")
    print(" ".join([str(x) for x in a]))     
    print(" ".join([str(x) for x in b])) 
    print(" ".join([str(x) for x in c])) 
else:
    print("NO")   