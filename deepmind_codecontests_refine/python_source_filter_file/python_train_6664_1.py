import sys
from heapq import *
H,O=[],[]
for e in sys.stdin:
 c=e[1]
 if'n'==c:heappush(H,-int(e[7:]))
 elif'x'==c:O+=[-heappop(H)]
print('\n'.join(map(str,O)))
