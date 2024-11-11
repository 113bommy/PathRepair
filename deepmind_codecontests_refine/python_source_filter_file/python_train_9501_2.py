#dt = {} for i in x: dt[i] = dt.get(i,0)+1
import sys;input = sys.stdin.readline
inp,ip = lambda :int(input()),lambda :[int(w) for w in input().split()]

for _ in range(inp()):
    n = inp()
    s = input().strip()
    prev = -1
    x = []
    for i in range(n):
        if s[i] != prev:
            x.append(0)
        x[-1] += 1
        prev = s[i]
    ans = 0
    if len(x) == 1:
        ans += (x[0]-1)//3 + 1
    else:
        if s[0] == s[-1] and len(x) > 1:
            t = x.pop()
            x[0] += t
        for i in x:
            ans += (i-3)//2 +1
    print(ans)
