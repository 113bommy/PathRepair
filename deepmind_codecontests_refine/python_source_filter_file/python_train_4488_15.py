import sys

n, k = map(int, input().split())

count = {}
for c in 'ABCDEFGHIKLMNOPQRSTVXYZ '[:k]:
    count[c] = 0

for i in range(n):
    ch = sys.stdin.read(1)
    if ch in count:
        count[ch] += 1

print(count[min(count, key=count.get)] * k)
