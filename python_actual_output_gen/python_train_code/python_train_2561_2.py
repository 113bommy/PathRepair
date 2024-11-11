for i in range(int(input())):
    s = list(input())
    if len(s) == 2:
        ns = s
    else:
        ns = []
        for i in range(0,len(s),2):
            ns.append(s[i])
        if len(s) % 2 == 0:
            ns.append(s[-1])
        print("".join(ns))

