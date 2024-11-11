from collections import *

s, t = deque(input()), input()
mem, a1, a2 = Counter(t), 0, 0

for i in range(len(s)):
    if mem[s[0]]:
        a1 += 1
        mem[s[0]] -= 1
        s.popleft()
    else:
        s.rotate(-1)
# print(s)
for i in s:
    if i.isupper() and mem[i.lower()]:
        a2 += 1
        mem[i.lower()] = 0
    elif i.islower() and mem[i.upper()]:
        a2 += 1
        mem[i.upper()] = 0

print(a1, a2)
