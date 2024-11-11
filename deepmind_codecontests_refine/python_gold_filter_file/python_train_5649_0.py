def p(s):
    res = 0
 
    best = 0
    cur = 0
    ans = len(s)
    for i in range(len(s)):
        res += 1
        if s[i] == '+':
            cur += 1
        else:
            cur -= 1
        if cur < best:
            ans += (i+1)
            best = cur
 
    return ans
 
for t in range(int(input())):
    s = input().strip()
    print(p(s))
