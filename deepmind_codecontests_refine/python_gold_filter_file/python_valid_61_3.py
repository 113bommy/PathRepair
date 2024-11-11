t = int(input())
for _ in range(t):
    n = int(input())
    l = [c for c in input()]

    while ('?' in l):
        for i in range(1,n-1):
            if l[i]=="B":
                if l[i-1]=="?":
                    l[i-1] = "R"
                if l[i+1]=="?":
                    l[i+1] = "R"
            if l[i]=="R":
                if l[i-1]=="?":
                    l[i-1] = "B"
                if l[i+1]=="?":
                    l[i+1] = "B"
        if l[0] == "R" and l[1] == "?":
            l[1] = "B"
        elif l[0] == "B" and l[1] == "?":
            l[1] = "R"
        elif l[n-1] == "R" and l[n-2] == "?":
            l[n-2] = "B"
        elif l[n-1] == "B" and l[n-2] == "?":
            l[n-2] = "R"
        
        if not("R" in l) or not("B" in l):
            l[0] = "R"

    print("".join(l))