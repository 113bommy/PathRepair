def solve():
    n, k = map(int, input().split())
    s = str(n)
    se = set()
    for i in range(len(s)):
        se.add(s[i])
    if len(se) <= k:
        return s
    se = set()
    i = 0
    while True:
        se.add(s[i])
        if len(se) > k:
            break
        i += 1
    se.remove(s[i])
    arr = sorted(se)
    while True:
        cur = set(c for c in s[:i])
        if len(cur) == k:
            if s[i] >= arr[-1]:
                i -= 1
                continue
            j = 0
            while arr[j] < s[i]:
                j += 1
            return s[:i] + arr[j] + arr[0]*(len(s)-i-1)
        c = str(int(s[i])+1)
        cur.add(c)
        r = min(cur) if len(cur) == k else "0"
        return s[:i] + c + r*(len(s)-i-1)



import sys
input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for i in range(t):
    print(solve())