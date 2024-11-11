n = int(input())
laptops = []
for i in range(n):
    ai, bi = map(int, input().split())
    laptops.append((bi, ai))


laptops = sorted(laptops, reverse=True)

price = laptops[-1][1]


for c in laptops:
    if c[1] > price:
        print('Happy Alex')
        quit()
    else:
        price = c[1]
print('Poor Alex')