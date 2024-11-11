string = input()
numbers = string.split()
a, b = int(numbers[0]), int(numbers[1])
n = a % b
while b % 2 == 0:
    b //= 2
if b == n:
    print("Yes")
else:
    print("No")