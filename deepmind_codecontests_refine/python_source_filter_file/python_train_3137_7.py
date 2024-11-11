t = int(input())
for i in range(t):
    s = [c for c in input().strip()]
    if len(set(s)) == 1:
        print(-1)
    else:
        sr = s
        sr.reverse()
        if s != sr:
            print(*s, sep='')
        else:
            print(*(s[1:]+s[0:1]), sep='')
