import math
N, Q = map(int, input().split())
queries = []
for i in range(Q):
    v, w = map(int, input().split())
    queries.append([v, w])

if N == 1:
    for v, w in queries:
        print(min(v, w))
else:
    for v, w in queries:
        if 1 in [v, w]:
            print(1)
        else:
            # v < w にする
            v, w = min(v,w), max(v, w)
            v -= 2
            w -= 2
            v_parents = [v]
            isReported = False
            while v > 0:
                v_parents.append(v // N - 1)
                v = v//N-1
            while w > 0:
                w = w // N-1
                if w in v_parents:
                    print(w+2)
                    isReported = True
                    break
            if not isReported:
                print(1)
        