from math import sqrt
import heapq

def calc(arr, i, j):
    d = sqrt((arr[i][0] - arr[j][0])**2 + (arr[i][1] - arr[j][1])**2)
    if arr[i][2] + arr[j][2] <= d:
        return d - arr[i][2] - arr[j][2]
    else:
        return 0

def main():
    xs, ys, xt, yt = map(int, input().split())
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]
    arr.append([xs, ys, 0])
    arr.append([xt, yt, 0])
    n += 2
    st = set()
    for i in range(n):
        st.add(i)
    dist = [float("inf")]*n
    dist[n-2] = 0
    dist[n-1] = calc(arr, n-2, n-1)
    hq = []
    heapq.heappush(hq, [0, n-2])
    while len(hq) > 0:
        _, p = heapq.heappop(hq)
        if p in st:
            st.remove(p)
            for nxt in st:
                d = calc(arr, p, nxt)
                if dist[nxt] > dist[p] + d:
                    dist[nxt] = dist[p] + d
                    heapq.heappush(hq, [dist[nxt], nxt])
    print(dist[-1])

if __name__ == "__main__":
    main()