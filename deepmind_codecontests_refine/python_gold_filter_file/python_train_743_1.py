n , k , m , t = map(int,input().split())

l = [1]*n

l[k-1] = "doc"

for i in range(t):
    op , idx = map(int,input().split())
    if op == 0:
        if idx < k:
            while idx:
                l.pop(0)
                idx -= 1
        else:
            idx = len(l) - idx
            while idx:
                l.pop()
                idx -= 1

        
        y = len(l)
        print(y,end=' ')
        for x in range(y):
            if l[x] == "doc":
                k = x+1
                print(x+1)
                break

    else:
        l.insert(idx-1,1)

        y = len(l)
        print(y,end=' ')
        for x in range(y):
            if l[x] == "doc":
                k = x+1
                print(x+1)
                break
    # print(l)