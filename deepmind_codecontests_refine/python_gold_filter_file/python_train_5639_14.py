stops = int(input())
capacity = 0
min_cap = 0
for s in range(stops):
    a, b = list(map(int, input().split(" ")))
    c = capacity
    capacity += b - a
    if capacity > min_cap:
        min_cap = capacity
print(min_cap)