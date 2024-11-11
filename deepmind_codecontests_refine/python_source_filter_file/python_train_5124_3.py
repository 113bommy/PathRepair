import sys

input = sys.stdin.readline

t = int(input().strip())

while t > 0:
    k = int(input().strip())
    s = input().strip()
    tmp = 1
    ans = 0
    change = 0
    for i in range(0, k - 1):
        if s[i] == "A" and s[i + 1] == "P":
            change += 1
            s = s[i + 1:]
            break
    for i in range(0, len(s) - 1):
        if s[i] == "P" and s[i] == s[i + 1]:
            tmp += 1
            ans = max(tmp, ans)
        else:
            ans = max(tmp, ans)
            tmp = 1
        if s[i] != s[i + 1]:
            change += 1
    if change is 0 or (change is 1 and s[-1] == "A"):
        ans = 0
    print(ans)
    t -= 1