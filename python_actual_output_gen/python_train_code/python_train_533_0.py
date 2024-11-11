n = int(input())
l, r = -2000000000, 2000000000
for i in range(n):
    s = input().split()
    if (s[2] == "N"):
        if (s[0] == ">"):
            s[0] = "<="
        elif (s[0] == "<"):
            s[0] = ">="
        elif (s[0] == ">="):
            s[0] = "<"
        elif (s[0] == "<="):
            s[0] = ">"
    if (s[0] == ">"):
        l = max(l, int(s[1]) + 1)
    elif (s[0] == "<"):
        r = min(r, int(s[1]) - 1)
    elif (s[0] == ">="):
        l = max(l, int(s[1]))
    elif (s[0] == ">="):
        r = min(r, int(s[1]))
if (l <= r):
    print(l)
else:
    print("Impossible")