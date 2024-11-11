n = int(input())
xs = [int(i) for i in input().split()]
for i in range(n):
    ind = i + 1
    ret = "node" + str(ind) + ":key = " + str(xs[ind - 1])
    if ind != 1:
        parent = ind // 2 - 1
        ret += ", parent key = " + str(xs[parent])
    if n > 2 * i + 1:
        ret += ", left key = " + str(xs[2 * i + 1])
    if n > 2 * i + 2:
        ret += ", right key = " + str(xs[2*i + 2])
    ret += ","
    print(ret)