not_possible = []

cities, num_not_possible = [int(x) for x in input().split()]

middle = 1

for i in range(num_not_possible):
    string = [int(x) for x in input().split()]
    if (string[0] == middle):
        middle += 1
    if (string[1] == middle):
        middle += 1
    not_possible.append((string[0], string[1]))

lst = list(sum(not_possible, ()))

for city in range(cities):
    if city not in lst:
        middle += city
        break

possible = []

for i in range(1, cities + 1):
    if (middle, i) not in not_possible and i != middle:
        possible.append((middle, i))

print(len(possible))

for i in range(len(possible)):
    print(possible[i][0], possible[i][1])
