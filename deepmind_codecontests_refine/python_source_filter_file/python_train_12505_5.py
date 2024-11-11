x = int(input())
if x < 4:
    if x == 2:
        print(2, 2)
    else:
        print(-1)
    exit(0)
print(str(x)+' '+str(x // 2) if x % 2 == 0 else str(x - 1)+' '+str((x - 1) // 2))