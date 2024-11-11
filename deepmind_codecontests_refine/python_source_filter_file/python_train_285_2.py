import heapq

def greedy(limit, n):
    ans = 0
    hq = []
    for i in range(n-1, -1, -1):
        for item in limit[i]:
            # 最大値を取り出したいので負で格納
            heapq.heappush(hq, -item)
        if hq:
            ans += -heapq.heappop(hq)
    return ans

def solve():
    n = int(input())
    left = []
    limit_l = [[] for i in range(n)]
    l_cnt = 0
    right = []
    limit_r = [[] for i in range(n)]
    r_cnt = 0
    ans = 0
    for i in range(n):
        k, l, r = map(int, input().split())
        ans += min(l, r)
        if l > r:
            # 左に並びたい
            limit_l[k-1].append(l-r)
            l_cnt+=1
        else:
            # 右に並びたい
            if n-k-1 > 0:
                limit_r[n-k-1].append(r-l)
            else:
                # 右のスコアを獲得できない
                pass
            r_cnt+=1
    ans += greedy(limit_l, n)
    ans += greedy(limit_r, n)
    print(ans)
    return 

t = int(input())
for i in range(t):
    solve()