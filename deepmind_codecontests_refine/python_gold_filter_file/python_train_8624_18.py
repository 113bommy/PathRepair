from itertools import product

def next_sw(ox, sw, prev_sw):
    if (ox == 'o' and sw == 'S') or (ox == 'x' and sw == 'W'):
        return prev_sw 
    else:
        return 'W' if prev_sw =='S' else 'S'

N = int(input())
S = input()
ans = [None] * (N+1)
ok = False
for ans[0], ans[1] in product('SW', 'SW'):
    for i in range(1, N):
        ans[i+1] = next_sw(S[i], ans[i], ans[i-1])
    if ans[0] == ans[-1] and ans[1] == next_sw(S[0], ans[0], ans[-2]):
        ok = True
        break
if ok:
    print(''.join(ans[:N]))
else:
    print(-1)

