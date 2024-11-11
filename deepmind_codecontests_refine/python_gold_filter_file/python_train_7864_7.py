n = int(input())

days = [int(bruh) for bruh in input().split()]

if days[-1] == 15:
    print("DOWN")
    exit()

if days[-1] == 0:
    print("UP")
    exit()

if len(days) == 1:
    print(-1)
    exit()

if days[-1] < days[-2]:
    print("DOWN")
    exit()

if days[-1] > days[-2]:
    print("UP")
    exit()


