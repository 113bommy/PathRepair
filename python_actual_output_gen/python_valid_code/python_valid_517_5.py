for _ in range(int(input())):
    s = input()
    t = input()
    s = s[::-1]
    t = t[::-1]

    k = 0
    last = -1
    ans = False
    for i in range(len(s)):
        if s[i] == t[k] and (k - last + 1) % 2 == 0:
            k += 1
            last = i
        if k == len(t):
            ans = True
            break
    print("YES" if ans else "NO")

