

def go():
    n = int(input())
    a = list(map(lambda s: int(s) - 1, input().split()))

    done = [False] * n

    root = a[0]
    done[root] = True

    target = n - 1
    while done[target]: target -= 1

    parent = [-1] * n
    hanging = root


    def set_parent(x, par):
        if parent[x] != -1:
            return False
        else:
            parent[x] = par
            done[x] = True
            return True


    i = 0
    while i < n - 2:
        i += 1
        if a[i] == target or done[a[i]]:
            son=target
        else:
            son=a[i]
        if not set_parent(son, hanging):
            print (-1)
            return
        while done[target]: target -= 1
        hanging = a[i]
    parent[target] = hanging

    print(root+1)
    for a,b in enumerate(parent):
        if b!=-1:
            print (a+1,b+1)

go()