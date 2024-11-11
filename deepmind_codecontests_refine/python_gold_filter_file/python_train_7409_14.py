import math

splits = input().split()
n,d = int(splits[0]), int(splits[1])

result = 0
numbers = input().strip().split()
numbers = [int(idx) for idx in numbers]
for i in range(1,n):
    diff = numbers[i] - numbers[i-1]
    if diff < 0:
        diff *= -1
        times = math.ceil(diff/d)
        numbers[i] += times * d
        result += times
        if numbers[i] == numbers[i-1]:
            numbers[i] += d
            result += 1
    elif diff == 0:
        numbers[i] += d
        result += 1
# print(numbers)
print(result)
