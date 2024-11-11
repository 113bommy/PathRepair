n = int(input())
for i in range(n):
    ch = int(input())
    if ch <= 3: print(-1)
    else:
        sum = ch // 4
        ch = ch % 4
        if ch==0 or ch == 2: print(sum)
        elif ch == 1:
            if sum >= 2: print(sum - 1)
            else: print(-1)
        elif ch == 3:
            if sum >= 3: print(sum - 2)
            else: print(-1)