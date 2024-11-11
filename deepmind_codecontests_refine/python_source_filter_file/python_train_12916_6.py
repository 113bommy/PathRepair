import sys
from collections import Counter
S = ""
for s in sys.stdin:
    s = s.strip()
    if not s:
        break
    S += s
for i in 'abcdefghijklmnopqrstuvwxyz':
    print(i, ":", S.count(i))

