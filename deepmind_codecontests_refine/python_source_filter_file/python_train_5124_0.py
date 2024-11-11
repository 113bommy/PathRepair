colomns = int(input())
t = 0
for i in range(colomns):
    l = []
    n = int(input())
    k = str(input())
    for j in range(len(k)):
        l.append(k[j])
    l1 = l.copy()
    c = 0
    t = 0
    while l.count("P") > 0:
        t = l.count("P")
        for m in range(len(l) - 1):
            if l[m] == "A" and l[m + 1] == "P":
                l1[m + 1] = "A"
        l = l1
        if t == l.count("P"):
            break
        c += 1
    print(c)