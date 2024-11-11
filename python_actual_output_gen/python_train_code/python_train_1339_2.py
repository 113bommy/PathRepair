n = int(input())
coins = sorted(map(int, input().split(' ')))[::-1]

v = sum(coins)
get = 0
             
for i in range(n):
    get += coins[-i]
    v -= coins[-i]
    if(get > v):
        print(i + 1)
        break
