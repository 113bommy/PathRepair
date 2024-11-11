import copy
def getchar(s):
    global a,b,c
    if s == "R":
        return "P"
    elif s == "P":
        return "S"
    elif s == "S":
        return "R"
    if a > 0:
        a -= 1
        return "R"
    if b > 0:
        b -= 1
        return "P"
    if c > 0:
        c -= 1
        return "S"

t = int(input())
for j in range(t):
    n = int(input())
    cc = 0
    a,b,c = map(int,input().split())
    s = list(input())
    ds = copy.copy(s)
    for i in range(n):
        if s[i] == "R":
            if b > 0:
                b -=1
                cc += 1
                s[i] = ""
        elif s[i] == "P":
            if c > 0:
                c -=1
                cc += 1
                s[i] = ""
        else:
            if a > 0:
                a -=1
                cc += 1
                s[i] = ""
    if (n + 1) // 2 <= cc:
        print("YES")
        for i in range(n):
            if s[i] == "":
                print(getchar(ds[i]),end  = "")
            else:
                print(getchar(""), end = "")
        print()
    else:
        print("NO")
