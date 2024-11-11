while True:
    N = int(input())
    if N == 0:
        break
    d = {}
    for n in range(N):
        num, p, q = map(int, input().split())
        if num in d:
            d[num][1] += (p*q) 
        else:
            d[num] = [n, p*q]
    else:
        fla = False
        for k, v in sorted(d.items(), key=lambda x[1][0]):
            if v[1] >= 1000000:
                print(k)
                fla = True
        else:
            if not fla:
                print('NA')