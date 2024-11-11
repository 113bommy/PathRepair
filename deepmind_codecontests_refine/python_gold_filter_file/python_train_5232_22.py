import os
### START FAST IO ###
inp = os.read(0, int(1e7)).split()
inp_pos = -1
def cin():
    global inp_pos
    inp_pos += 1
    return inp[inp_pos]
# cout: os.write(1, "\n".encode().join(res))
#### END FAST IO ####

from bisect import bisect

T = int(cin())
res = []
while T:
    T -= 1
    n = int(cin())
    a = sorted([(int(cin()), i) for i in range(n)])
    before = [0 for i in range(n)]
    after = [0 for i in range(n)]
    pre = [-1 for i in range(n)]
    start = 0
    for i in range(n):
        if i == 0:
            before[a[i][1]] = 1
        elif a[i][0] != a[i-1][0]:
            before[a[i][1]] = 1 + bisect(a, (a[i-1][0], a[i][1]), start, i) - start
            start = i
        if i > 0:
            pre[a[i][1]] = a[i-1][1]
    last = n
    for i in range(n-1, -1, -1):
        if i == n-1:
            after[a[i][1]] = 0
        elif a[i][0] != a[i+1][0]:
            after[a[i][1]] = last - bisect(a, (a[i+1][0], a[i][1]), i+1, last)
            last = i+1
    ans = 0
    dp = [0 for i in range(n+1)]
    for i in range(n):
        dp[i] = max(before[i], dp[pre[i]] + 1)
        ans = max(ans, dp[i] + after[i])
    res.append(str(n-ans).encode())
os.write(1, "\n".encode().join(res))
