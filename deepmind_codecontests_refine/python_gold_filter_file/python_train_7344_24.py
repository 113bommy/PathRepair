string = input()
numbers = string.split()
a = int(numbers[0])
b = int(numbers[1])
c = int(numbers[2])
string = input()
numbers = [int(x) for x in string.split()]
n = 0
e = 0
for x in numbers:
    if x <= b:
        n += x
        if n > c:
            n = 0
            e += 1
print(e)