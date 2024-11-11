n = int(input())
coins = sorted(list(map(int, input().split())), reverse = True)

summ = sum(coins)
x = max(coins)

counter = 1

for i in range(n):
    if x > summ - x:
        break

    else:
        x += coins[i]
        counter += 1

print(counter)
        
