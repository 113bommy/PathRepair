# alepha = ["a", "b", "c", "d", "e",
# "f", "g", "h", "i", "j",
# "k", "l", "m", "n", "o",
# "p", "q", "r", "s", "t",
# "u", "v", "w", "x", "y", "z"]
a, b = map(int, input().split())
s = input()
if b / a > 25:
    print(-1)
else:
    ans = ""
    c = 0
    for i in s:
        if b == 0:
            ans += s[c:]
            break
        idx = ord(i) - 97
        if idx >= 13:
            if b > idx:
                ans += "a"
                b -= idx
            else:
                ans += chr(idx + 97 - b)  # alepha[idx - b]
                b = 0

        else:
            if b > 25-idx:
                ans += "z"
                b -= 25 - idx
            else:
                ans += chr(idx + 97 + b)  # alepha[idx + b]
                b = 0
        c += 1
    if b == 0:
        print(ans.lower())
    else:
        print(-1)
