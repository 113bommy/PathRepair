string = input()
numbers = string.split()
a = int(numbers[0])
b = int(numbers[1]) * 100
sweets = [-1]
for x in range(a):
    string = input()
    numbers = string.split()
    d = int(numbers[0])
    c = int(numbers[1])
    m = d * 100 + c
    if b > m:
        sweets.append(-c % 100)
print(max(sweets))