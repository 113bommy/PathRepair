import sys
from collections import defaultdict
d = defaultdict(int)
for i in sys.stdin:
    d[int(i)] +=1
m = max(v for v in d.values())
for i in sorted([k for k, v in d.items() if v == m]):
    print(i)