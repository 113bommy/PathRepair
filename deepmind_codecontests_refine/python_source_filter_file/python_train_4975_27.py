N = int(input())
T = [[] for _ in range(N)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    T[a].append(b)
    T[b].append(a)


colors = [-1] * N
stack = [(0, 0)]
while stack:
    n, color = stack.pop()
    colors[n] = color
    for to in T[n]:
        if colors[to] != -1:
            continue
        stack.append((to, color ^ 1))


# あまり１、あまり２、あまり０になるように並び替え
X = [[] for _ in range(3)]
for n in range(1, N + 1):
    X[n % 3].append(n)
X.append(X[0])
del X[0]


ans = []
x12, x3 = X[0] + X[1], X[2]
if colors.count(0) <= N // 3:
    for color in colors:
        if color == 0:
            ans.append(x3.pop())
        elif x12:
            ans.append(x12.pop())
        else:
            ans.append(x3.pop())

elif colors.count(1) <= N // 3:
    for color in colors:
        if color == 1:
            ans.append(x3.pop())
        elif x12:
            ans.append(x12.pop())
        else:
            ans.append(x3.pop())

else:
    for color in colors:
        if X[color]:
            ans.append(X[color ^ 1].pop())
        else:
            ans.append(X[2].pop())

print(' '.join(map(str, ans)))
