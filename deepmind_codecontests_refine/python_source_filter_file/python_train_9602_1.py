#!/usr/bin/env python3
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
s = list(input().rstrip())

ans = []
while True:
    ok = True
    epoch = []
    for i, (s1, s2) in enumerate(zip(s, s[1:])):
        if s1 == "R" and s2 == "L":
            epoch.append(i + 1)
            ok = False
    if ok:
        break
    ans.append(epoch)
    for item in epoch:
        s[item-1], s[item] = s[item], s[item - 1]

minima = len(ans)
maxima = 0
for line in ans:
    maxima += len(line)

if k < minima or k > maxima:
    print(-1)
    exit()
skip = k - minima
ans_str = []
for line in ans:
    if skip == 0:
        ans_str.append(str(len(line)) + " ".join([str(item) for item in line]))
        continue
    val = min(skip, len(line) - 1)
    for _ in range(val):
        item = line.pop()
        ans_str.append("1 " + str(item))
    skip -= val
    if line:
        ans_str.append(str(len(line)) + " " + " ".join([str(item) for item in line]))
print("\n".join(ans_str))