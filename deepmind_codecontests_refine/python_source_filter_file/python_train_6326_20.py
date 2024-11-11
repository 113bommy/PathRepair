n,m = map(int,input().split())
l = list(map(int,input().split()))
s = 0
while True:
    if  len(l) > 0:
        if  l[0] <= m:
            s += 1
            del(l[-1])
        elif l[0] <= m:
            s += 1
            del(l[0])
        else:
            print(s)
            exit()
    else:
        print(s)
        exit()