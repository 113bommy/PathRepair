line = input()
t = int(line)
for _ in range(t):
    s = input()
    res, cur, mx = 0, 0, 0
    for i in range(len(s)):
        if s[i] == '+':
            cur += 1
        else: 
            cur -= 1
        if cur < mx:
            mx = cur
            res -= mx
    print(res + len(s))
