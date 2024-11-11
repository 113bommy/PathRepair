T = int(input())

while (T != 0):
    T -= 1

    N, K = map(int, input().split())
    cur_usage = 0
    reslog = 0
    cnts = dict()

    while True:
        reslog += 1
        cur_usage +=  (1 << reslog) - 1
        if reslog != N:
            cnts[reslog] = (((1 << reslog)-2)<<1) + 1

        if cur_usage + (1 << (reslog+1))-1 > K or reslog == N:
            break

    K -= cur_usage

    while K > 0:
        if len(cnts) == 0:
            break
        for key in cnts:
            K -= cnts[key]
            if key+1 >= N:
                del cnts[key]
                break
            if (key+1 not in cnts):
                cnts[key+1] = 0
            cnts[key+1] += cnts[key] * 4
            del cnts[key]
            break




    if K <= 0:
        print('YES %d' % (N-reslog))
    else:
        print('NO')
        




