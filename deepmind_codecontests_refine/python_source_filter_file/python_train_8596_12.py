n, k = [int(x) for x in input().split()]

discounted = [int(x) for x in input().split()]
regular = [int(x) for x in input().split()]

prices = zip(discounted, regular)

prices = sorted(prices, key=lambda x: x[0])
prices = sorted(prices, key=lambda x: x[0]-x[1])

# print(prices)

k_cost = sum(x[0] for x in prices[:k])

after_k_cost = 0
idx = k
for i, price in enumerate(prices[k:]):
  if price[0] < price[1]:
    after_k_cost += price[0]
  idx = i

idx += k + 1

after_discount_cost = sum(x[1] for x in prices[idx:])

# print(k_cost, after_k_cost, after_discount_cost)

print(k_cost + after_k_cost + after_discount_cost)