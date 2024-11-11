from sys import stdin
from collections import defaultdict

line = stdin.readline().rstrip()
n = int(line)

a = []
for line in stdin.readlines():
    line = line.rstrip()
    start, end = [int(x) for x in line.split(' ')]
    a.append((start, end))

m = defaultdict(int)

for i, k in enumerate(a):
    x1, y1 = k
    for j in range(i+1, len(a)):
        x2, y2 = a[j]
        m[(x1+x2,y1+y2)] += 1

ct = 0
for k, v in m.items():
    ct += v*(v-1)//2

print(ct)