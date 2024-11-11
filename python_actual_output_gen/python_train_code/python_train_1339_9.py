total_coins = int(input())
coins_arr = list(map(int, input().split(' ')))
coins_arr.sort()
total_amount = sum(coins_arr)
my_money = 0
no_coins_taken = 0

while not my_money > total_amount:
    taken_coin = coins_arr.pop(0)
    my_money += taken_coin
    total_amount -= taken_coin
    no_coins_taken += 1

print(no_coins_taken)
