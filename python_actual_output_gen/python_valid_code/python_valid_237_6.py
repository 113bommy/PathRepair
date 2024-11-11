for _ in range(int(input())):
    n = int(input())
    gr = list(map(int,input().split()))
    gr = sorted(gr)
    a = n+1
    i = n-1
    while i>=0:
        if gr[i]<=a:
            break
        else:
            a = a - 1
            i -= 1
    print(a)    