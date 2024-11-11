import sys
from heapq import *
H=[]
O=''
for e in sys.stdin:
 if'i'==e[0]:heappush(H,-int(e[7:]))
 elif'x'==e[1]:O+=f'{-heappop(H)}\n'
print(O[:-1])
