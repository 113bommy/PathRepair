# -*- coding: utf-8 -*-

# Baqir Khan
# Software Engineer (Backend)

from sys import stdin

inp = stdin.readline

n, k = map(int, inp().split())
s = inp()[:-1]
out_time = [-1] * 26
in_time = [-1] * 26

for i in range(n):
    if in_time[ord(s[i]) - ord("A")] == -1:
        in_time[ord(s[i]) - ord("A")] = i

for i in range(n - 1, -1, -1):
    if out_time[ord(s[i]) - ord("A")] == -1:
        out_time[ord(s[i]) - ord("A")] = i

requirement = [0] * (n + 1)

for i in range(26):
    if in_time[i] != -1:
        requirement[in_time[i]] += 1
        requirement[out_time[i] + 1] -= 1

cur_sum = 0
for i in range(n):
    cur_sum += requirement[i]
    requirement[i] = cur_sum

print("YES" if max(requirement) <= k else "NO")
