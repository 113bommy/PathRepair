import copy
w, h = map(int,input().split())
while [h, w] != [0, 0]:
    area = []
    a = 1
    for i in range(h):
        area.append(list(input()))
        area[i].insert(0,"#")
        area[i].append("#")
    area.insert(0,["#" for i in range(w + 2)])
    area.append(["#" for i in range(w + 2)])

    que = []
    for i in range(h):
        for j in range(1, w + 1):
            if area[i][j] == "@":
                que.append([i, j])
                break
        else:
            continue
        break
    while True:
        nque = []
        for i in que:
            h1 = i[0]
            w1 = i[1]
            if area[h1 - 1][w1] == ".":
                area[h1 - 1][w1] = "*"
                nque.append([h1 - 1, w1])
                a += 1
            if area[h1 + 1][w1] == ".":
                area[h1 + 1][w1] = "*"
                nque.append([h1 + 1, w1])
                a += 1
            if area[h1][w1 - 1] == ".":
                area[h1][w1 - 1] = "*"
                nque.append([h1, w1 - 1])
                a += 1
            if area[h1][w1 + 1] == ".":
                area[h1][w1 + 1] = "*"
                nque.append([h1, w1 + 1])
                a += 1
        if nque == []:
            break
        que = copy.deepcopy(nque)

    print(a)
        
    w, h = map(int,input().split())
