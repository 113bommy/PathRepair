hm = int(input())

for _ in range(hm):
    inp = list(input())
    ac = inp.count("A") + inp.count("C")
    b = inp.count("B")
    if ac - b <= 0:
        print("YES")
    else:
        print("NO")
