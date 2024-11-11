import re
s, t = input().replace('?', '.'), input()
l, m = len(s), len(t)

if l < m:
    print("UNRESTORABLE")
    exit()

can = []  # candidates
for i in range(l - m + 1):
    if re.match(s[i:i + m], t)
        can.append((s[:i] + t + s[i + m:]).replace('.', 'a'))
print(min(can) if can else "UNRESTORABLE")