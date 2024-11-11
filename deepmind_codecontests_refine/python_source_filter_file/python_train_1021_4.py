H, W = map(int, input().split())
S = ["."*(W+2)] + ["." + input() + "." for _ in range(H)] + ["."*(W+2)]
for y in range(1, H+1):
    for x in range(1, W+1):
        if S[y][x] = '#' and (S[y-1][x] + S[y+1][x] + S[y][x-1] + S[y][x+1]).count('#') == 0:
            print("No")
            exit()
print("Yes")