import sys
from heapq import *
H,O=[],[]
for e in sys.stdin:
 c=e[2]
 if's'==c:heappush(H,-int(e[7:]))
 elif't'==c:O+=[-heappop(H)]
print('\n'.join(map(str,O)))
