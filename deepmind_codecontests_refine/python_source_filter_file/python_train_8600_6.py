n = int(input())
for i in range(n):
    z = int(input())
    if z in range(1,12):
        if z in (8,10):
            ans = 2
        elif z in (1,2,3,5,7):
            ans = -1
        else:
            ans = 1
    else:
        ans = (z // 4) - (z % 2)
    print(ans)