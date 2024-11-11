n, a, b = map(int, input().split())
place = n - a
if place > b:
    place -= (b + 1)
print(place)
