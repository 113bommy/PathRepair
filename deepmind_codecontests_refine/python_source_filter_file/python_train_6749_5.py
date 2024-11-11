n = int(input())
ans = 0
red = sorted([list(map(int, input().split())) for _ in range(n)], key=lambda x:-x[0])
blue = sorted([list(map(int, input().split())) for _ in range(n)])
for i in red:
    for num, j in enumerate(blue):
        if i[0] < j[0] and i[1] < j[1]:
            ans += 1
            del blue[num]
            break
print(ans)