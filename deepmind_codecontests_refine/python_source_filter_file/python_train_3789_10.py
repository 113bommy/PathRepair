#B. Sereja and Array
n,m = map(int,input().split())
a = list(map(int,input().split()))
acc = 0
for i in range(m):
    query = list(map(int,input().split()))
    if query[0] == 1:
        a[query[1]-1] = query[2]
    elif query[0] == 2:
        acc += query[1]
    elif query[0] == 3:
        print(a[query[1]-1]+acc)