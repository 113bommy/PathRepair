from collections import *

n, s, ans, mem = int(input()), list(input()), 0, defaultdict(int)
for i in range(0, n, 2):
    if s[i] == 'r':
        if i == n - 1 or i < n - 1 and s[i + 1] == 'b':
            mem['rb'] += 1
        else:
            mem['rr'] += 1
    else:
        if i == n - 1 or i < n - 1 and s[i + 1] == 'r':
            mem['br'] += 1
        else:
            mem['bb'] += 1

ans += max(mem['bb'], mem['rr']) + min(mem['rb'], mem['br'])

if n & 1:
    if mem['bb'] < mem['rr']:
        if s[-1] == 'b' and mem['rb'] > mem['br']:
            ans -= 1
    elif mem['bb'] > mem['rr']:
        if s[-1] == 'r' and mem['rb'] < mem['br']:
            ans -= 1

print(ans)
