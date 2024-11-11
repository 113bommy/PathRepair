a, b = map(int, input().split(" "))
aa, bb = bin(a)[2:], bin(b)[2:]

ans = 0
if len(aa) == len(bb):
    s = ["1"]*len(aa)
    for i in range(1, len(s)):
        s[i] = "0"
        ss = int("".join(s), 2)
        if ss >= a and ss <= b:
            ans += 1
        s[i] = "1"
else:
    s = ["1"]*len(aa)
    for i in range(1, len(s)):
        s[i] = "0"
        ss = int("".join(s), 2)
        if ss >= a:
            ans += 1
        s[i] = "1"
    s = ["1"]*len(bb)
    for i in range(1, len(s)):
        s[i] = "0"
        ss = int("".join(s), 2)
        if ss <= b:
            ans += 1
        s[i] = "1"
    for i in range(len(aa)+1, len(bb)):
        ans += i-1

print(ans)
