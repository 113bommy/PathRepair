from heapq import heappush, heappop
H, W, T, Q = map(int, input().split())
que = []
state = [[0]*W for i in range(H)]
data1 = [[0]*(W+1) for i in range(H+1)]
data2 = [[0]*(W+1) for i in range(H+1)]
def get(data, h, w):
    s = 0
    while h:
        w0 = w
        el = data[h]
        while w0:
            s += el[w0]
            w0 -= w0 & -w0
        h -= h & -h
    return s
def add(data, h, w, x):
    while h <= H:
        w0 = w
        el = data[h]
        while w0 <= W:
            el[w0] += x
            w0 += w0 & -w0
        h += h & -h

for q in range(Q):
    t, c, *ps = map(int, input().split())
    while que and que[0][0] <= t:
        _, h0, w0 = heappop(que)
        add(data1, h0, w0, -1)
        add(data2, h0, w0, 1)
        state[h0][w0] = 2
    if c == 0:
        h0, w0 = ps
        state[h0][w0] = 1
        add(data1, h0, w0, 1)
        heappush(que, (t + T, h0, w0))
    elif c == 1:
        h0, w0 = ps
        if state[h0][w0] == 2:
            add(data2, h0, w0, -1)
            state[h0][w0] = 0
    else:
        h0, w0, h1, w1 = ps
        result1 = get(data1, h1, w1) - get(data1, h1, w0-1) - get(data1, h0-1, w1) + get(data1, h0-1, w0-1)
        result2 = get(data2, h1, w1) - get(data2, h1, w0-1) - get(data2, h0-1, w1) + get(data2, h0-1, w0-1)
        print(result2, result1)