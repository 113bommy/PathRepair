t = int(input())
for _ in range(t):
    answer = 0
    n, k = map(int, input().split())
    barrels = list(map(int, input().split()))
    barrels.sort()
    max_water = barrels[-1]
    for idx in range(1,k+1):
        max_water += barrels[-1-k]
    answer = max_water
    print(answer)