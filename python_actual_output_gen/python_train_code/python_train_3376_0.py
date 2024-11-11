import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().strip()

    ans = (str(s), 1)
    for k in range(2, n+1):
        if n-k+1 %2 == 0:
            sp = s[k-1:] + s[:k-1]
        else:
            sp = s[k-1:] + s[:k-1][::-1]
        if sp < ans[0]:
            ans = (sp, k)
    print(ans[0])
    print(ans[1])
