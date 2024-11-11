buy, sell = {}, {}
n, depth = map(int, input().split())
for i in range(n):
	direction, price, volume = input().split()
	price, volume = int(price), int(volume)
	if direction == 'B':
		if price in buy: buy[price] += volume
		else: buy[price] = volume
	else:
		if price in sell: sell[price] += volume
		else: sell[price] = volume

for i, price in enumerate(sorted(sell.keys())[:depth:-1]):
	print("S {price} {volume}".format(price = price, volume = sell[price]))

for i, price in enumerate(sorted(buy.keys())[::-1]):
	if i < depth:
		print("S {price} {volume}".format(price = price, volume = buy[price]))