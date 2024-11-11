tiles = list(input())
crucial = [0,0]
for i in tiles:
    if i == "0":
        if crucial[0] == 0:
            crucial[0] = 1
            print("3 4")
        else:
            crucial[0] = 0
            print("1 4")
    else:
        if crucial[1] == 0:
            crucial[1] = 1
            print("1 1")
        else:
            crucial[1] = 0
            print("1 4")