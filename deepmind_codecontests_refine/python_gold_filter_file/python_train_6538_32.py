from collections import deque
H, W = map(int, input().split())
m = [[-1 if c == "." else 0 for c in input() + "#"] for _ in range(H)]
m.append([0] * (W + 1))
todo = deque(((h, w) for h in range(H) for w in range(W) if m[h][w] == 0))
ans = 0
while todo:
    h, w = todo.popleft()
    count = m[h][w] + 1
    for dh, dw in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        nh = h + dh
        nw = w + dw
        if m[nh][nw] == -1:
            m[nh][nw] = count
            todo.append((nh, nw))
            ans = count
print(ans)