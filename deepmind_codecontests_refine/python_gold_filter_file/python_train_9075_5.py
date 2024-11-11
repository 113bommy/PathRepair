a = input()
b = set(a)
c = list(a)
if (("4" in b) or ("7" in b)):
    a1 = c.count("4")
    a2 = c.count("7")
    if a1>=a2:
        print("4")
    else:
        print("7")
else:
    print("-1")