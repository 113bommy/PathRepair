import sys


line =  sys.stdin.readline()
vals = line.split()
vnum = int(vals[0])
glength = int(vals[1])

line =  sys.stdin.readline()
vals = line.split()
vsizes =[]
for val in vals:
    vsizes.append(int(val))
    
vsizes.sort(reverse = True)
for vsize in vsizes:
    if glength % vsize == 0:
        print(glength/vsize)
        break
    
    
    
