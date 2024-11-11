string = input()
numbers = string.split(" ")
a = int(numbers[0])
b = int(numbers[1])
c = int(numbers[2])
condition = c - a == 0 or c - a >= b
if (c - a) % b <= 1 and condition:
    print("YES")
else:
    print("NO")