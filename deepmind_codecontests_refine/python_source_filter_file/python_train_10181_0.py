N = int(input())
X = sorted([list(map(int, input().split())) for _ in range(N)], key=lambda x: (x[0], -x[1]))


front = []
most_left_R = float('inf')
for l, r in X:
    most_left_R = min(r, most_left_R)
    front.append(max(0, most_left_R - l + 1))

back = []
most_left_R = float('inf')
for l, r in X[::-1]:
    most_left_R = min(r, most_left_R)
    back.append(max(0, most_left_R - X[-1][0] + 1))
back = back[::-1]

ans = 0
for i in range(N - 1):
    ans = max(ans, front[i] + back[i + 1])

# most_left_R = min([r for l, r in X])
# for l, r in X:
#     ans = max(ans, (r - l + 1) + max(0, most_left_R - X[-1][0] + 1))
print(ans)
