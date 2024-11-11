N = int(input())
Red = [list(map(int, input().split())) for _ in range(N)]
Blue = [list(map(int, input().split())) for _ in range(N)]

Red.sort(key=lambda x: x[1], reverse=True)
Blue.sort(key=lambda x: x[0])

ans = 0
for blue in Blue:
    for red in Red:
        if red[0] < blue[0] and red[1] < blue[1]:
            ans += 1
            Red.remove(red)
            break

print(ans)
