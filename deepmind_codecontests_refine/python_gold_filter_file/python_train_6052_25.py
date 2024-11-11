s = input()
vert = 0
hori = 0
for c in s:
    if c == '1':
        hori += 1
        if hori == 1: print("1 3")
        elif hori == 2: print("2 3")
        elif hori == 3: print("3 3")
        else:
            hori = 0
            print("4 3")
    else:
        vert += 1
        if vert == 1: print("1 1")
        else:
            print("3 1")
            vert = 0