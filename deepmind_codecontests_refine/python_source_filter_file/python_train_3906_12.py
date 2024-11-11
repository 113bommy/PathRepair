string = input()
numbers = string.split()
a, b, floors, times = int(numbers[0]), int(numbers[1]), [], []
for x in range(a):
    string = input()
    numbers = string.split()
    floors.append(int(numbers[0]))
    times.append(int(numbers[1]))
floors, times = floors[::-1], times[::-1]
n = 0
for x in range(a):
    n += b - floors[x]
    b = floors[x]
    if times[x] > n:
        n = times[x]
n += b