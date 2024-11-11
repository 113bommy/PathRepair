nb_cities, fuel_limit = [int(x) for x in input().split()]
if nb_cities - 1 <= fuel_limit:
    print(nb_cities - 1)
else:
    cost = fuel_limit - 1
    for i in range(1, nb_cities - fuel_limit):
        cost += i
    print(cost)
