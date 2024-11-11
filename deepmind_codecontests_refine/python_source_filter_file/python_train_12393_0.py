import sys
for n in sys.stdin:
 if n=='0 0':break
 print(*sorted(map(int,n.split())))