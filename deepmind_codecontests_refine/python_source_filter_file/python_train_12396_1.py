import sys
for a in sys.stdin:
 if a=='0 0':break
 print(*sorted(map(int,a.split())))