inyear = int(input())
n = []
for t in range(1,10):
    for h in range(10):
        for d in range(10):
            for u in range(10):
                if t != h and t != d and t != u:
                    if h != d and h != u:
                        if d != u:
                            n.append(int(str(t)+str(h)+str(d)+str(u)))
for year in n:
    if year > inyear:
        print(year)
        break
