cities, location = map(int, input().split())
criminals = list(map(int, input().split()))

distances = [0] * cities
for i in range(cities):
    if criminals[i] == 1:
        distances[abs(location - i - 1)] += 1

left_cities = cities - location
right_cities = location - 1

catch = 0

for current in range(cities):
    if current == 0:
        catch += distances[current]
    elif current < left_cities and current < right_cities:
        if distances[current] == 2:
            catch += 1
    else:
        catch += distances[current]

print(catch)