h = 1
v = 1
for c in input():
    if c != '1':
        print(2, v)
        if v < 4:
            v += 1
        else:
            v = 1
    else:
        print(1, h)
        h = 4 - h
