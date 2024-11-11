import collections
h, w = [int(_) for _ in input().split()]
S = [list('.' * (w + 1))] + [['.'] + list(input()) for _ in range(h)]
B = [[99999] * (w + 1) for _ in range(h + 1)]
B[1][1] = 0 if S[1][1] == '.' else 1
cand = collections.deque([(1, 2), (2, 1)])
while cand:
    x, y = cand.popleft()
    if B[x][y] == 99999:
        B[x][y] = min(B[x][y - 1] + (S[x][y] == '#' != S[x][y - 1]),
                      B[x - 1][y] + (S[x][y] == '#' != S[x - 1][y]))
        if x < h:
            cand += [(x + 1, y)]
        if y < w:
            cand += [(x, y + 1)]
print(B)
