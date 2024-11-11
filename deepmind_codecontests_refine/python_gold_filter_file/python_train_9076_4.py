t = int(input())

for i in range(t):
    s = input()
    i = 0
    ans = ""
    l = 0
    while l < len(s):
        r = l
        cur = 0
        while r < len(s) and s[l] == s[r]:
            cur += 1
            r += 1
        ans += s[l] * (cur % 2)
        l = r
    ans = list(set(ans))
    ans.sort()
    print("".join(ans))
