# take most
games = int(input())
for game in range(games):
    n = int(input())
    ps = list(map(int, input().split()))
    max_v = max(ps)
    sum_v = sum(ps)
    if (max_v > sum_v - max_v or sum_v % 2 == 1):
        print("T")
    else:
        print("HL")
