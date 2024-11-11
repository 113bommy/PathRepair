
n = int(input())

for _ in range(n):
    s = [c for c in input()]
    s.append("R")
    last = "j"
    nope = False
    for i in range(len(s)-1):
        if last == s[i]:
            nope = True
            break
        if s[i] != "?":
            last = s[i]
            continue
        if last == s[i+1] or last=='j' or s[i+1]=="?" or s[i+1] == "R":
            if s[i+1] == 'a' or last == 'a':
                s[i] = 'b'
            else:
                s[i] = 'a'
            last = s[i]
            continue
        if last == 'a' and s[i+1]=="b":
            s[i] = "c"
            last = "c"
            continue
        if last == 'b' and s[i+1]=="a":
            s[i] = "c"
            last = "c"
            continue
        if last == 'a' and s[i+1]=="c":
            s[i] = "b"
            last = "b"
            continue
        if last == 'c' and s[i+1]=="a":
            s[i] = "c"
            last = "c"
            continue
        if last == 'c' and s[i+1]=="b":
            s[i] = "a"
            last = "a"
            continue
        if last == 'b' and s[i+1]=="c":
            s[i] = "a"
            last = "a"
            continue
    if nope:
        print(-1)
    else:
        print("".join(s[:-1]))
