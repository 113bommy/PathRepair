R = lambda : map(int, input().split())
s = input()
n = int(input())
words = [input() for i in range(n)]
dp = [-1] * len(s)
for w in words:
    si = 0
    while si != -1:
        si = s.find(w, si)
        if si >= 0:
            dp[si + len(w) - 1] = max(si + 1, dp[si + len(w) - 1])
            si += 1
fl = 0
fr = 0
l = 0
found = False
for r in range(len(s)):
    if dp[r] >= 0:
        l = dp[r]
    if r - l > fr - fl:
        found = True
        fl, fr = l, r
print(fr - fl + found, fl)