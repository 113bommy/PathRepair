x = int(input())
while not all(x % i for i in range(2, x)):
    x += 1
print(x)