# python 3

n_val, c_val = list(map(int, input().split()))
trade = list(map(int, input().split()))

profit = list()
for day in range(1, n_val):
    profit.append(trade[day] - trade[day-1])
profit_max = min(profit)
if profit_max >= 0:
    profit_max = 0
else:
    profit_max = abs(profit_max) - c_val
print(profit_max)
