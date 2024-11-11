import sys
from heapq import *
H,O=[],[]
for e in sys.stdin:
 t=e[1]
 if'n'==t:heappush(H,-int(e[7:]))
 elif'x'==t:O+=[-heappop(H)]
print('\n'.join(map(str,O)))
