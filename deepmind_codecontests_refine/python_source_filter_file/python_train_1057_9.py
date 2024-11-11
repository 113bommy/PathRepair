x, y, price = map(int, input().split())

max_buy = (x+y) // price
x = x // price
y = y // price

min_cost = min(price - x, price - y) if (x+y) > price else 0

print(max_buy, min_cost)