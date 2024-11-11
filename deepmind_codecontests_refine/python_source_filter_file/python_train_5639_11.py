n = int(input())
capacity = 0
minicapacity = 0
for i in range (1, n +1):
    a, b = map(int, input().split())
    if (i == 1):
        capacity = minicapacity = b
    if a < capacity and 1 < i < n +1:
        capacity = capacity + (b-a)
        if capacity > minicapacity:
            minicapacity = capacity
    if (i == n):
        capacity = capacity - a
print (minicapacity)