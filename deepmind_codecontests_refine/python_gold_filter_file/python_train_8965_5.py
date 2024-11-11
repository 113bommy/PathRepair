for s in [*open(0)][1:]:
    a, b, c, d = map(int, s.split())
    print(a,d if a != d else c)