def replace(n, array):
    res = []
    pos = {}
    for i in range(n + 1):
        pos[i] = []
    for i in range(n):
        pos[array[i]].append(i)

    end = False
    while not end:
        for i in range(n + 1):
            if not pos[i]:
                mex = i
                break
        if mex < n:
            if array[mex] != mex:
                pos[array[mex]].remove(mex)
                array[mex] = mex
                pos[mex].append(mex)
                res.append(mex)
        else:
            j = 0
            while j < n:
                if array[j] != j:
                    pos[array[j]].remove(j)
                    array[j] = n
                    pos[n].append(j)
                    res.append(n)
                    break
                j += 1
            if j == n:
                end = True

    for i in range(len(res)):
        res[i] += 1

    print(len(res))
    print(*res)


t = int(input())
for i in range(t):
    n = int(input())
    array = [int(s) for s in input().split()]
    replace(n, array)