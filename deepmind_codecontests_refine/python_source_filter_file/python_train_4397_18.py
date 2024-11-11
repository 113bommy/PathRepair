import sys
input = lambda : sys.stdin.readline()
n = int(input())
for i in range(n):
    a = int(input())
    c = list(map(lambda x: (int(x[1]),x[0]),enumerate(input().split())))
    d = list(map(lambda x: (int(x[1]),x[0]),enumerate(input().split())))
    c.sort()
    d.sort()
    print(' '.join(map(lambda x: str(x[i]),c)))
    print(' '.join(map(lambda x: str(x[i]), c)))

