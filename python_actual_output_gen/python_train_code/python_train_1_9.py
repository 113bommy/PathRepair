q = int(input())
while q>0:
    l,r,d = map(int,input().split())
    if l > d:
        print(d)
    elif d >= l and d <= r:
        print(r - d)
    else:
        print(d)
    q = q - 1