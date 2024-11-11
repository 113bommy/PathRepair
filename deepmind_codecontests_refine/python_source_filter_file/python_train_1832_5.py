s=input()
if len(s)%2==0:
    t=s[:len(s)//2]
    y=s[len(s)//2:]
    y=y[::-1]
    c=0
    for i in range(len(s)//2):
        if t[i]!=y[i]:
            c=c+1
    if c>1:
        print("NO")
    else:
        print("YES")
else:
    t = s[:len(s) // 2]
    y = s[len(s) // 2+1:]
    y = y[::-1]
    c = 0
    for i in range(len(s) // 2):
        if t[i] != y[i]:
            c = c + 1
    if c > 1:
        print("NO")
    else:
        print("YES")
