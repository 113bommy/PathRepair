import heapq

def main():
    n, m = map(int, input().split())
    dics = [{} for _ in range(n)]
    for _ in range(m):
        l, r, c = map(int, input().split())
        ky = r-1
        if ky in dics[l-1]:
            if c < dics[l-1][ky]:
                dics[l-1][ky] = c
        else:
            dics[l-1][ky] = c
    dist = [float("inf")]*n
    dist[0] = 0
    hq = []
    heapq.heappush(hq, [0, 0])
    idx = 0
    while len(hq) > 0:
        v, p = heapq.heappop(hq)
        if p < idx:
            continue
        if p == n-1:
            break
        for i in range(idx+1, p):
            if len(dics[i]) > 0:
                for ky in dics[i].keys():
                    if ky in dics[p]:
                        if dics[p][ky] > dics[i][ky]:
                            dics[p][ky] = dics[i][ky]
                    else:
                        if p < ky:
                            dics[p][ky] = dics[i][ky]
        idx = p
        for r in dics[p].keys():
            if dist[r] > v + dics[p][r]:
                dist[r] = v + dics[p][r]
                heapq.heappush(hq, [v + dics[p][r], r])
    if dist[n-1] == float("inf"):
        print(-1)
    else:
        print(dist[n-1])

if __name__ == "__main__":
    main()
