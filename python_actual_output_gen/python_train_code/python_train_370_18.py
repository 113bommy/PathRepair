x, y, z = map(int, input().split())

num_no_exchange = x // z + y // z
num_exchange = (x + y) // z
if num_exchange > num_no_exchange:
    print(num_exchange, min(x % z, y % z))
else:
    print(num_exchange, 0)
