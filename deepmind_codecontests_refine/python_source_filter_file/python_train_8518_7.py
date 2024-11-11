s = input()
if s.replace("A","") == "KIHBR":
    befores = ["HBR"]
    flg = True
    for i, _s in enumerate(s[1:], 1):
        if _s == "A" and s[i-1] not in befores:
            flg = False
    print("YES" if flg else "NO")
else:
    print("NO")