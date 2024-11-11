def main():
    from sys import setrecursionlimit, stdin, stderr
    from os import environ
    from collections import defaultdict, deque, Counter
    from math import ceil, floor
    from itertools import accumulate, combinations, combinations_with_replacement
    setrecursionlimit(10**6)
    dbg = (lambda *something: stderr.write("\033[92m{}\033[0m".format(str(something)+'\n'))) if 'TERM_PROGRAM' in environ else lambda *x: 0
    input = lambda: stdin.readline().rstrip()
    LMIIS = lambda: list(map(int,input().split()))
    II = lambda: int(input())
    P = 10**9+7
    INF = 10**18+10
    N = II()
    #positions = defaultdict(defaultdict(int))
    #planes = []
    #1:U 2:R 3: D 4:L
    U = 0
    R = 1
    D = 2
    L = 3
    direction = {'U':U,'R':R,'D':D,'L':L}
    
    x_axis = defaultdict(list)
    y_axis = defaultdict(list)
    ru = defaultdict(list)
    dr = defaultdict(list)
    ld = defaultdict(list)
    ul = defaultdict(list)
    

    for i in range(N):
        line = input().split()
        x = int(line[0])
        y = int(line[1])
        d = direction[line[2]]

        #planes.append((x,y,d))

        #positions[y][x] = d
        
        
        sum_cordinate = x+y
        dif_cordinate = x-y
        if d == U:
            y_axis[x].append((y,d))
            ul[dif_cordinate].append((x,y,d))#(x1,y1)(x2,y2)y2-y1=x2-x1, y2-x2=y1-x1
            ru[sum_cordinate].append((x,y,d))
        elif d == R:
            x_axis[y].append((x,d))
            ru[sum_cordinate].append((x,y,d))
            dr[dif_cordinate].append((x,y,d))
        elif d == D:
            y_axis[x].append((y,d))
            dr[dif_cordinate].append((x,y,d))
            ld[sum_cordinate].append((x,y,d))
        else:
            x_axis[y].append((x,d))
            ld[sum_cordinate].append((x,y,d))
            ul[dif_cordinate].append((x,y,d))

    

    min_time = 10**20
    for v in x_axis.values():
        v.sort()
        i = 0
        while i < len(v)-1:
            if v[i][1] ==  R:
                j = i+1
                while j < len(v):
                    if v[j][1] == L:
                        min_time = min(min_time, (v[j][0]-v[i][0])*5)
                        break
                    j += 1
                i = j
            i += 1

    for v in y_axis.values():
        v.sort()
        i = 0
        while i < len(v)-1:
            if v[i][1] ==  U:
                j = i+1
                while j < len(v):
                    if v[j][1] == D:
                        min_time = min(min_time, (v[j][0]-v[i][0])*5)
                        break
                    j += 1
                i = j
            i += 1
    
    for v in ru.values():
        #x座標でソート
        v.sort()
        i = 0
        while i < len(v)-1:
            if v[i][2] == R:
                j = i+1
                while j < len(v):
                    if v[j][2] == U:
                        min_time = min(min_time,(v[j][0]-v[j-1][0])*10)
                        break
                    j += 1
                i = j
            i += 1
    
    for v in dr.values():
        #x座標でソート
        v.sort()
        i = 0
        while i < len(v)-1:
            if v[i][2] == R:
                j = i+1
                while j < len(v):
                    if v[j][2] == D:
                        min_time = min(min_time,(v[j][0]-v[j-1][0])*10)
                        break
                    j += 1
                i = j
            i += 1
    
    for v in ld.values():
        #x座標でソート
        v.sort()
        i = 0
        while i < len(v)-1:
            if v[i][2] == D:
                j = i+1
                while j < len(v):
                    if v[j][2] == L:
                        min_time = min(min_time,(v[j][0]-v[j-1][0])*10)
                        break
                    j += 1
                i = j
            i += 1
    
    for v in ul.values():
        #x座標でソート
        v.sort()
        i = 0
        while i < len(v)-1:
            if v[i][2] == U:
                j = i+1
                while j < len(v):
                    if v[j][2] == L:
                        min_time = min(min_time,(v[j][0]-v[j-1][0])*10)
                        break
                    j += 1
                i = j
            i += 1


    print(min_time if min_time < 10**20 else 'SAFE')
    

    

    



    
main()