for _ in range(int(input())):
    n = int(input())
    s = input()
    if len(set(s)) == 1:
        print(-1, -1)
    else:
        if s[0]=="a":
            p = s.find("b")
        else:
            p = s.find("a")
        print(p+1, p+2)