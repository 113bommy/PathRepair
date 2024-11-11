import functools

n = int(input())
cities = [int(x) for x in input().split(" ")]

min_n = 1000000000
count_min = 0
min_i = -1

for i, city in enumerate(cities):
    if city < min_n:
        min_n = city
        count_min = 1
        min_i = i
    elif city == min_n:
        count_min += 1

if count_min == 1:
    print(min_i + 1)
else:
    print("Still Rozdil")