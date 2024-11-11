h = int(input())
key = list(map(int,input().split()))
key.insert(0,0)

for i in range(h):
    k = i + 1
    lk = 2*k
    rk = 2*k + 1
    pk = int(0.5*k)
    if k == 1:
        print("node {0}: key = {1}, left key = {2}, right key = {3}, ".format(k, key[k], key[lk], key[rk]))
    elif lk > h:
        print("node {0}: key = {1}, parent key = {2}, ".format(k, key[k], key[pk]))
    elif rk > h:
        print("node {0}: key = {1}, parent key = {2}, left key = {3},".format(k, key[k], key[pk], key[lk]))
    else:
        print("node {0}: key = {1}, parent key = {2}, left key = {3}, right key = {4}, ".format(k, key[k], key[pk], key[lk], key[rk]))