s = input()
if len(s)%2==0:
    p = s[:len(s)//2]
    o = s[:len(s)//2-1:-1]
    ww = 0
    for i in range(len(p)):
        if o[i]!=p[i]:
            ww += 1
    if ww>1:
        print("NO")
    else:
        print("YES")
else:
    p = s[:len(s)//2]
    o = s[:len(s)//2:-1]
    ww = 0
    for i in range(len(p)):
        if o[i]!=p[i]:
            ww += 1
    if ww>1:
        print("NO")
    else:
        print("YES")
