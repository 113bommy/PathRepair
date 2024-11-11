n = int(input())
counter, x, sm = 1, 1, 0

while sm <= n:
    counter += 1
    x += counter
    sm += x
    # print(x)

print(counter - 1)