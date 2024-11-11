import sys
input = sys.stdin.readline

def main():

    n, q = map(int, input().split())

    V = []

    for i in range(n):
        s, t, x = map(int, input().split())
        V.append((s-x, x, 1)) #1: insert
        V.append((t-x, x, 0)) #0: delete

    D = []
    for i in range(q):
        d = int(input())
        V.append((d, i, 2)) #2: query

    V.sort(key=lambda x:(x[0], x[2]))
    se = set()
    hq = []
    import heapq
    heapq.heapify(hq)
    ans = [-1]*q
    for t, v, p in V:
        if p == 1:
            se.add(v)
            heapq.heappush(hq, v)
        elif p == 0:
            se.remove(v)
        else:
            while hq and hq[0] not in se:
                heapq.heappop(hq)
            if hq:
                ans[v] = hq[0]

    for i in range(q):
        print(ans[i])

if __name__ == '__main__':
    main()