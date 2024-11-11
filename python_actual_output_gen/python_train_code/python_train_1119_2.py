S = input()
lS, ans = len(S), [0] * len(S)

for i in range(lS):
    if S[i:i + 2] == 'RL':
        r = i
    if S[i] == 'L':
        ans[r + ((i - r) % 2)] += 1
    if S[(lS - i - 2):(lS - i)] == 'RL':
        l = (lS - i - 1)
    if S[(lS - i - 1)] == 'R':
        ans[l - ((i - l + 1) % 2)] += 1

print(' '.join(map(str, ans)))
