import sys
for _ in range(int(sys.stdin.readline())):
    n = int(sys.stdin.readline())
    s = sys.stdin.readline()[:n]
    sys.stdout.write('%d\n' % (sum(int(s) for i in s)+sum(i != '0' for i in s[:-1])))
