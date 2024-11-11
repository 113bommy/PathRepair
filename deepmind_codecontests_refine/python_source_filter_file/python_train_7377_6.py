import collections
import sys
cntr = collections.Counter
for line in sys.stdin:
    cntr[int(line)] += 1
lst = []
for k,v in cntr.items():
    lst.append((v,k))
lst.sort()
t = len(lst)-1
while t>0 and lst[t][0] == lst[t-1][0]:
    t -= 1
for i in range(t,len(lst)):
    print(lst[i][1])