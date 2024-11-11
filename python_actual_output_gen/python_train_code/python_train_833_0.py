useless = input()
numbers = input().split()
def local_extremums(array):
    numbers = list(map(int,array))
    i = 1
    result = 0
    while i < len(numbers) - 1:
        if (numbers[i] < numbers[i-1] and numbers[i] <  numbers[i + 1]) or (numbers[i] > numbers[i-1] and numbers[i] >  numbers[i + 1]):
            result += 1
        i += 1
    return result
print(local_extremums)
