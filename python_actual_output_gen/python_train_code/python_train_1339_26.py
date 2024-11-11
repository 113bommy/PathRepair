n = int(input())
coins = sorted(list(map(int, input().split())), reverse=True)
for i in range(n):
    if sum(coins[:i]) > sum(coins)/2:
        print(i)
        break