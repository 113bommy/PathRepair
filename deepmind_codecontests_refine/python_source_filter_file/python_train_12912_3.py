import sys
from collections import Counter
m = Counter(sys.stdin.readlines.lower())
for i in 'abcdefghijklmnopqrstuvwxyz':
    print(i, ":", m[i])
