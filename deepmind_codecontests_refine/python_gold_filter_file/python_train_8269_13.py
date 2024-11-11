laptops = []

for n in range(int(input())):
    price, quality = map(int, input().split(" "))
    laptops.append((price, quality))

laptops.sort(key=lambda x: (x[0], x[1]))

# print(laptops)
for i in range(len(laptops)):
    if laptops[i][0] != laptops[i][1]:
        print("Happy Alex")
        quit()

print("Poor Alex")
