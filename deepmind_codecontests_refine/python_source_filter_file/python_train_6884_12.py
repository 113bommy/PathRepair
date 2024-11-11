n = input()
t = 0
if n.count('[') < 1 or n.count(']') < 1:
    print(-1)
else:
    for i in range(len(n)):
        if n[i] == '[':
            c = i
            break
        t += 1
    for i in range(len(n)-1,-1,-1):
        if n[i] == ']':
            d = i
            break
        t += 1
    s = n[c+1:d]
    if s.count(':') < 2:
        print(-1)
    else:
        for i in range(len(s)):
            if s[i] == ':':
                c = i
                break
            t += 1
        for i in range(len(s)-1,-1,-1):
            if s[i] == ':':
                d = i
                break
            t += 1
        s = s[c+1:d]
        for i in s:
            if i!= '|':
                t += 1
        print(t)
