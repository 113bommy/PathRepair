#! python3
# disjoint_set_union_find_tree.py

n, q = [int(x) for x in input().split(' ')]

sets = [set([i]) for i in range(n)]

def unite(Sx, Sy):
    return Sx | Sy

def search(x):
    global sets
    flag = False
    for i in range(len(sets)):
        if x in list(sets[i]):
            flag = True
            break
    if flag:
        return i
    else:
        return None

def same(x, y):
    global sets
    flag = 0
    for set in sets:
        if x in set:
            if y in set:
                 flag = 1
            break
    return flag

for i in range(q):
    query, x, y = input().split(' ')
    x, y = int(x), int(y)
    if query == '0':
        # unite
        i_x = search(x)
        i_y = search(y)
        if i_x != None and i_y != None and i_x != i_y:
            sets[i_x] = unite(sets[i_x], sets[i_y])
            del sets[i_y]
    elif query == '1':
        # same
        print(same(x, y))

