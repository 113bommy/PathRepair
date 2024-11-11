t = int(input())

for _ in range(t):
    s = input()
    x = int(input())
    w = [-1] * len(s)
    for i in range(len(s)):
        ch = s[i]
        if ch == "0":
            if i - x >= 0:
                w[i - x] = 0
            if i + x < len(s):
                w[i + x] = 0
    for i in range(len(s)):
        ch = s[i]
        if ch == "1":
            if ((i - x < 0 and i + x >= len(s)) or (i - x >= 0 and w[i - x] == 0 and i + x >= len(s)) or
                    (i - x < 0 and i + x < len(s) and w[i + x] == 0)
                    or (i - x < 0 and i + x >= len(s) and w[i + x] == 0 and w[i - x] == 0)):
                print(-1)
                break
    else:
        for i in range(len(w)):
            if w[i] == -1:
                w[i] = 1
            w[i] = str(w[i])
        print("".join(w))
