for h in range(int(input())):
    p = sorted(input())
    s = input()
    n = len(p)
    m = len(s)
    if(m < n):
        print("NO")
        break
    for i in range(m - n + 1):
        y = 0
        if(sorted(s[i:i+n]) == p):
            y = y + 1
            break
    if(y > 0):
        print("YES")
    else:
        print("NO")