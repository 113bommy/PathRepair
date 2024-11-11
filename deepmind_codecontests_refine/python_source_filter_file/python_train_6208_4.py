def ans(inp):
    sm = sum(inp)
    if sm % 2 == 1:
        print("NO")
        return
    for a in range(6):
        for b in range(6):
            for c in range(6):
                if a != b and b != c:
                    s = inp[a] + inp[b] + inp[c]
                    if s*2 == sm :
                        print("YES")
                        return
    print("NO")

inp = input().split(" ")
inp = list(map(int, inp))
ans(inp)
