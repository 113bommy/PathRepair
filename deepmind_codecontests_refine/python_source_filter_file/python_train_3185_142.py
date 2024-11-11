a, b = map(int, input().split())
years = 0

while a < b:
    a += a * 3
    b += b * 2
    years += 1

print(years)