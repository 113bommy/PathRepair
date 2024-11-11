string = input()
numbers = string.split(" ")
n = int(numbers[0])
a = int(numbers[1])
angle = (n - 2) * 180 / n
angles = []
for x in range(1, n - 1):
    y = angle / (n - 2) * x
    angles.append(abs(y - a))
x = angles.index(min(angles)) + 3
print("1 2 %d" % (x))