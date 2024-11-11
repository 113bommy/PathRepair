while 1:
    N = int(input())
    if N == 0:break
    cals = [ list(map(int,input().split())) for i in range(N)]
    P,Q,R,C = list(map(int,input().split()))
    res = [ x for x in cals if x[1]<=P and x[2]<=Q and x[3]<=R and 4*x[1] + 9*x[2] + 4*x[3]]
    if len(res) == 0:print('NA')
    else:
        for i in res:
            print(i[0])