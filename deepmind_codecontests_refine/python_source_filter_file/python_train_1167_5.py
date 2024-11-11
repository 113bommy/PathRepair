for _ in range(int(input())):
    n = int(input())
    packages = set()
    xm, ym = 0, 0
    xpack = [[] for i in range(1069)]
    for i in range(n):
        x, y = map(int, input().split())
        xpack[x] += [y]

    x, y = 0, 0
    ans = ""
    poss = True
    extra = ""
    for i in range(1001):
        if not xpack[i]:
            extra += "R"
            y += 1
        else:
            ans += extra
            extra = ""
            for each in sorted(xpack[i]):
                if x > each:
                    poss = False
                    break
                else:
                    ans += "U"*(each-x)
                    x = each
            ans += "R"
            y += 1
    if poss:
        print("YES")
        print(ans)
    else:
        print("NO")



