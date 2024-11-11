import sys
sys.setrecursionlimit(10**9)
INF = float('inf')

def main():
    n, m, p = map(int,input().split())
    es = []
    for _ in range(m):
        e = list(map(int,input().split()))
        es.append([e[0]-1,e[1]-1,- e[2] + p])

    v_cost = [INF]*n
    v_cost[0] = 0
    for v in range(n*2):
        for e in es:
            frm = e[0]
            to = e[1]
            if v_cost[to] > v_cost[frm]+e[2]:
                v_cost[to] = v_cost[frm]+e[2]
                #if v >= n:
                #    v_cost[to] = -INF
        if v == n-1:
            prev = v_cost[-1]

    if prev != v_cost[-1]:
        return -1

    return max(0,-v_cost[-1])
   

if __name__ =="__main__":
    print (main())
