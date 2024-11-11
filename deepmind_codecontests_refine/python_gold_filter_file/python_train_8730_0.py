from itertools import product

while True:
    try:
        n = int(input())
    except:
        break
    count = sum(a + b + c + d == n for a, b, c, d in product(range(10), repeat=4))
    print(count)