import sys
n = int(sys.stdin.readline().rstrip())
m = int(sys.stdin.readline().rstrip())
l = []
for i in range(m):
    l.append(list(map(int, sys.stdin.readline().rstrip().split(','))))
print(l)
for i in range(n):
    cur = i+1
    for d in l[::-1]:
        if cur in d:
            cur = d[0] if cur == d[1] else d[1]
    print(cur)