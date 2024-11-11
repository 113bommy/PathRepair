while 1:
    ba = 0

    p = [0 for i in range(int(input()))]
    if len(p) == 0:break

    for i,v in enumerate(list(input())):
        p[i%len(p)] += 1
        if v == 'L':
            p[i%len(p)] += ba
            ba = 0
        elif v== 'S':
            ba += p[i%len(p)] 
            p[i%len(p)] = 0

    result = ''
    for v in p:
       result +=  '%d ' % v
    result += str(ba)
    print(result)