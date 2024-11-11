def main():
    from sys import setrecursionlimit, stdin, stderr
    from os import environ
    from collections import defaultdict, deque, Counter
    from math import ceil, floor
    from itertools import accumulate, combinations, combinations_with_replacement, product
    setrecursionlimit(10**6)
    dbg = (lambda *something: stderr.write("\033[92m{}\033[0m".format(str(something)+'\n'))) if 'TERM_PROGRAM' in environ else lambda *x: 0
    input = lambda: stdin.readline().rstrip()
    LMIIS = lambda: list(map(int,input().split()))
    II = lambda: int(input())
    P = 10**9+7
    INF = 10**12

    N = II()
    positions = deque()
    for i in range(N):
        positions.append(LMIIS())
    
    #縦、横の最短距離
    v = []
    h = []
    for i in range(2**N):
        v.append([INF]*N)
        h.append([INF]*N)
    for i in range(2**N):
        v_lines = deque([0])
        h_lines = deque([0])
        for j in range(N):
            if 2 ** j & i:
                v_lines.append(positions[j][0])
                h_lines.append(positions[j][1])
        for j,(x,y,p) in enumerate(positions):
            min_x = INF
            min_y = INF
            for x_c in v_lines:
                min_x = min(min_x, abs(x_c - x)*p)
            for y_c in h_lines:
                min_y = min(min_y, abs(y_c - y)*p)
            v[i][j] = min_x
            h[i][j] = min_y

    ans = [INF]*(N+1)
    #for pattern in product(range(3),repeat=N):
    n_bit_mask = (1<<N)-1
    for pattern in range(2**N):
        
        cities = [i for i in range(N) if 2**i&pattern==0]
        key = N - len(cities)
        

        pattern_v = pattern
        pattern_h = 0
        
        while True:
            sum_diff = 0
            for i in cities:
                sum_diff += min(v[pattern_v][i],h[pattern_h][i])
            ans[key] = min(ans[key], sum_diff)
            if pattern_v == 0:
                break
            pattern_v = (pattern_v-1)&pattern
            pattern_h = pattern - pattern_v
    print('\n'.join(map(str,ans)))





            



    

    



    
main()