string = input()
numbers = string.split()
a, b = int(numbers[0]), int(numbers[1])
k = 0
for x in range(a):
    n = input()
    for y in range(b):
        if not str(y) in n:
            break
    else:
        k += 1
print(k)