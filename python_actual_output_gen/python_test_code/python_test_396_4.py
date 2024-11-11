import sys
for e in sys.stdin.readlines():
 print(len(sum(map(int,e.split()))))
