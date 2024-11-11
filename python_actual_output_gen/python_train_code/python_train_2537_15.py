nb_orange, max_orange, max_waste = [int(x) for x in input().split()]
empties = 0
oranges = [int(x) for x in input().split()]
juiced = 0
for i in range(nb_orange):
    if oranges[i] <= max_orange:
        juiced += oranges[i]
        if juiced >= max_waste:
            empties += 1
            juiced = 0
print(empties)

