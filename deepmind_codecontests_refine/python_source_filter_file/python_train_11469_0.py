import copy
from collections import defaultdict

BIG = 10**9
N, M = [int(i) for i in input().split()]

K = [0] + [int(i) for i in input().split()]

sumK = sum(K)
max_days = 2*sum(K)

day_at_sale_per_item = defaultdict(list)
for i in range(M):
    day, item = [int(i) for i in input().split()]
    day_at_sale_per_item[item].append(day)

sales_per_day = defaultdict(list)
for item, days in day_at_sale_per_item.items():
    for day in days:
        sales_per_day[day].append(item)

L, R = 0, max_days
answer = 0
while L <= R:
    m = (L+R)//2

    def get_best_sales(m):
        best_sales = defaultdict(list)
        for item, days in day_at_sale_per_item.items():
            best_day = 0
            for day in days:
                if day < m:
                    best_day = max(best_day, day)
            if best_day:
                best_sales[best_day].append(item)
        return best_sales

    def available_sales(m):
        available_money = 0
        nb_sales = 0
        cK = copy.deepcopy(K)

        best_sales = get_best_sales(m)

        for day in range(1, m+1):
            available_money += 1
            for item in best_sales[day]:
                buy = min(cK[item], available_money)
                if buy:
                    cK[item] -= buy
                    available_money -= buy
                    nb_sales += buy
        return nb_sales

    def possible(m):
        total_money = m
        needed_money = 2 * sumK - available_sales(m)
        return total_money >= needed_money

    if possible(m):
        answer = m
        R = m-1
    else:
        L = m+1
print(answer)
