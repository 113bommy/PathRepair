import sys

r = set()
c = set()
n = int(sys.stdin.readline().split()[0])

l = sys.stdin.readline().split()
while l:
    x,y = l
    r.add(x)
    c.add(y)
    sys.stdout.write(str((n-len(r))*(n-len(y))) + ' ')
    l = sys.stdin.readline().split()
