n = int(input())
s = [list(input()) for i in range(n)]
ans = 0
for a in range(n):
    check = True
    for x in range(n):
        for y in range(x):
            if s[(x+a)%n][y] != s[(y+a)%n][x]:
                check = False
                break
        if check == False:
            break
    if check:
        ans += n-a
    if a == 0:
        continue
    check = True
    for x in range(n):
        for y in range(x):
            if s[x][(y+a)%n] != s[(y+a)%n][x]:
                check = False
                break
        if check == False:
            break
    if check:
        ans += n-a
print(ans)