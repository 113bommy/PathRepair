for _ in range(int(input())):
    n = int(input())
    s = list(input())
    if len(set(s)) == 1:
        print("".join(s))
        print(1)
    else:
        m = min(s)
        ans = s[:]
        ind = 1
        for i, c in enumerate(s):
            fs = s[i:] + s[:i][::1 if i % 2 == 0 else -1]
            if fs < ans:
                ans = fs
                ind = i + 1
        print("".join(ans))
        print(ind)