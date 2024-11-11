for _ in range(int(input())):
    a,b = map(int,input().split())
    c = len(str(b))-1
    if b == int('9'*len(str(b))):
        c += 1
    print(min(191,a)*c)
