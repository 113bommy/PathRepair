def index(a, el):
    for i in range(len(a)):
        if a[i] == el:
            return i
    return -1

t = int(input())
for _ in range(t):
    m, n = map(int, input().split())
    a = list(map(int, input().split()))
    p = list(map(int, input().split()))
    for i in range(len(p)):
        p[i] = p[i] - 1
    sortable = True
    for i in range(len(a)):
        minelind = index(a[i:], min(a[i:]))
        for j in range(minelind-1, i-1, -1):
            if j in p:
                temp = a[j]
                a[j] = a[j+1]
                a[j+1] = temp
            else:
                sortable = False
        #print("a: ", a, "mineldin: ", minelind)
    if sortable:
        print("YES")
    else:
        print("NO")
