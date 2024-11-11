##import sys
##sys.setrecursionlimit(1000000)

def DFS(tree, cat, pos, prev, isCat, m, count, travel, visit):
    while len(travel) > 0: #perulangan berlanjut selama stack travel tidak kosong
##        print("pos =", pos, "len tree[pos] =",len(tree[pos]), "travel =", travel)
##        print(cat)
        if int(isCat[pos]) and visit == 0: #jika pada node tersebut ada kucing dan cat
            cat[pos] += int(isCat[pos]) + cat[prev] #maka cat[pos] akan ditambah
##            print("cat[pos] =", cat[pos], "cat[prev] =", cat[prev], "isCat[pos] =", isCat[pos], "prev =", prev, "pos =", pos)
        elif not int(isCat[pos]):
            cat[pos] = 0
        if cat[pos] <= m:
            if len(tree[pos]) == 1 and pos != 0 and visit[pos] == 0:
##                print("pos =", pos, "len tree[pos] =", len(tree[pos]), "count =", count)
                count += 1
                travel.pop()
                visit[pos] = 1
                prev = pos
                pos = travel[len(travel) - 1]
            else:
                index = 0
                if len(tree[pos]) > 0:
                    if tree[pos][index] == prev:
                        tree[pos].pop(0)
                if len(tree[pos]) > 0:
                    travel += [tree[pos][index]]
                    visit[pos] = 1
                    prev = pos
                    pos = travel[len(travel) - 1]
                else:
                    travel.pop()
                    if len(travel) > 0:
                        prev = pos
                        pos = travel[len(travel) - 1]
        else: #untuk node yang menemui cat berturut-turut lebih dari m
            travel.pop()
            if len(travel) > 0:
                prev = pos
                pos = travel[len(travel) - 1]
##    print("pos =", pos, "len tree[pos] =", len(tree[pos]), "count =", count, end=' ')
##    if int(isCat[pos]):
##        cat += int(isCat[pos])
##    else:
##        cat = 0
####    print("cat =", cat)
##    if cat <= m:
##        if len(tree[pos]) == 1 and pos != 0:
##            count += 1
##        else:
##            for i in range(len(tree[pos])):
##                if tree[pos][i] != prev:
##                    count = DFS(tree, cat, tree[pos][i], pos, isCat, m, count)
    return count

line = input().split()
n = int(line[0])
m = int(line[1])
##limit = n - 1
tree = []
##visit = [0] * n
for i in range(n):
    tree.append([]) #inisialisasi tree
visit = [0]*n #menyimpan node yang belum dikunjingi
isCat = input().split() #menyimpan ada tidaknya cat pada node
count = 0
travel = [0] #stack untuk DFS
cat = [0]*n #array untuk menyimpan berapa banyak cat berturut pada posisi tersebut
for i in range(n-1):
    xy = input().split()
    tree[int(xy[0]) - 1].append(int(xy[1]) - 1) #proses pembuatan tree dengan edgenya
    tree[int(xy[1]) - 1].append(int(xy[0]) - 1)
##print(tree)
count = DFS(tree, cat, 0, 0, isCat, m, count, travel, visit)

##path = [0]
##pos = 0
##prev = 0
####print(tree)
##while len(path) > 0:
####    print(pos+1)
####    if pos == limit:
####        count += 1
####        break
##    if int(isCat[pos]) and cat[pos] == 0:
##        cat[pos] += 1 + cat[prev]
####    print(pos+1, "cat =",cat, "count =", count, "visit pos =", visit[pos])
##    if len(tree[pos]) > 0 and cat[pos] <= m:
##        path += [tree[pos][0]]
##        tree[pos].pop(0)
##        visit[pos] = 1
##        prev = pos
##        pos = path[len(path) - 1]
##    elif cat[pos] > m:
##        visit[pos] = 1
##        path.pop()
##        if len(path) > 0:
##            prev = pos
##            pos = path[len(path) - 1]
##    else:
####        print(pos+1)
##        if visit[pos] == 0 and cat[pos] <= m:
##            count += 1
##        visit[pos] = 1
##        path.pop()
##        if len(path) > 0:
##            prev = pos
##            pos = path[len(path) - 1]
##
print(count)
##input()