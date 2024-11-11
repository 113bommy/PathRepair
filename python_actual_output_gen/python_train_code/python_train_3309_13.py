n, a, b = map(int, input().split())
place = n - a
if place > b + 1:
    place -= (b + 1)
print(place)
