n, m = map(int, input().split())
l = [-1]*n
for i in range(m):
    a, b, c = map(int, input().split())
    if(l[a-1] == -1 and l[b-1] == -1 and l[b-1] == -1):
        l[a-1] = 1
        l[b-1] = 2
        l[c-1] = 3
    elif(l[a-1] == -1 and l[b-1] == -1):
        k = [1, 2, 3]
        k.remove(l[c-1])
        l[a-1] = k[0]
        l[b-1] = k[1]
    elif(l[c-1] == -1 and l[b-1] == -1):
        k = [1, 2, 3]
        k.remove(l[a-1])
        l[c-1] = k[0]
        l[b-1] = k[1]
    elif(l[a-1] == -1 and l[c-1] == -1):
        k = [1, 2, 3]
        k.remove(l[b-1])
        l[a-1] = k[0]
        l[c-1] = k[1]
print(*l)