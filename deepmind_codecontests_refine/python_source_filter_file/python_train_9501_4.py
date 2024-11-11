from itertools import groupby

def solve():
    n = int(input())
    s = input()

    if all(i == s[0] for i in s):
        print(n // 2)
        return
    
    if s[0] == s[-1]:
        if s[0] == 'R':
            idx = s.index('L')
            s = s[idx:] + 'R' * idx
        else:
            idx = s.index('R')
            s = s[idx:] + 'L' * idx
    
    res = 0
    for _, v in groupby(s):
        sz = len(list(v))
        res += sz // 3
    print(res)

for _ in range(int(input())):
    solve()
