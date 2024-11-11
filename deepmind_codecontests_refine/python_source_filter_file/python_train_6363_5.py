pts = [list(map(int, input().split())) for i in range(3)]
pts.sort()
ans = []
for i in range(pts[0][0], pts[1][0]):
    ans.append([i, pts[0][1]])
for i in range(min(pts[0][1], max(pts[1][1], pts[2][1])), max(pts[0][1], max(pts[1][1], pts[2][1])) + 1):
    ans.append([pts[1][0], i])
for i in range(pts[1][0] + 1, pts[2][0] + 1):
    ans.append([i, pts[2][1]])
print(len(ans))
for elem in ans:
    print(*elem)