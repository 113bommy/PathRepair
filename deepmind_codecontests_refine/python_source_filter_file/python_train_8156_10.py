x, y, a, b = map(int, input().split())
ans = []
for i in range(b, y+1):
    for j in range(a, x+1):
        if j > i:
            ans.append([j, i])
print(len(ans))
for li in ans:
    print(li[0], li[1])
