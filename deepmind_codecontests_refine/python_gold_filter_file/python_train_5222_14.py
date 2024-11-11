n, h, m = [int(thing) for thing in input().split()]
max_profit = 0
dictionary = {}
for i in range(1, n + 1):
    dictionary[i] = 3.14
for i in range(m):
    l, r, x = [int(thing) for thing in input().split()]
    for this in range(l, r + 1):
        if dictionary[this] is not 3.14:
            if dictionary[this] > x:
                dictionary[this] = x
        else:
            dictionary[this] = x
for that in range(1, n+1):
    if dictionary[that] is 3.14:
        max_profit += h**2
    else:
        max_profit += dictionary[that]**2
print(max_profit)
