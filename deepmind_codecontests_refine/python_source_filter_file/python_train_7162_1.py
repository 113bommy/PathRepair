N = int(input())
Points = [list(map(int, input().split())) for i in range(N)]

X_dict = {i: [] for i in range(1, 10 ** 5 + 1)}
Y_dict = {i: [] for i in range(1, 10 ** 5 + 1)}
for i, (x, y) in enumerate(Points):
    X_dict[x].append((y, i))
    Y_dict[y].append((x, i))


ans = 0
Visited = [False] * N
for i, (x, y) in enumerate(Points):
    if Visited[i]:
        continue

    stack = [('x', x), ('y', y)]
    cnt = 1
    x_set, y_set = {x}, {y}
    Visited[i] = True
    while stack:
        s, v = stack.pop()
        if s == 'x':
            for yd, j in Y_dict[v]:
                if Visited[j]:
                    continue
                else:
                    cnt += 1
                    y_set.add(yd)
                    stack.append(('y', yd))
                    Visited[j] = True
        else:
            for xd, j in X_dict[v]:
                if Visited[j]:
                    continue
                else:
                    cnt += 1
                    x_set.add(xd)
                    stack.append(('x', xd))
                    Visited[j] = True

    ans += len(x_set) * len(y_set) - cnt

print(ans)
