string = input()
numbers = string.split()
a, b, n = int(numbers[0]), int(numbers[1]), int(input())
numbers = [a, b]
for x in range(2, 6):
    numbers.append(numbers[x - 1] - numbers[x - 2])
print(numbers[n % 6] % (10 ** 9 + 7))