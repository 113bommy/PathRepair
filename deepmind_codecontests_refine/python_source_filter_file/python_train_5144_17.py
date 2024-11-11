string = input()
numbers = string.split()
n = int(numbers[1])
string = input()
numbers = [int(x) for x in string.split()]
a = 0
for x in numbers:
    if x < 0:
        a += 1
print(-sum(sorted(numbers)[:-min([a, n]) + 1]))