numbers = list(map(int, input().split()))
a = numbers[0]
b = numbers[1]
c = numbers[2]
if a > c or a > b:
    print("No")
else:
    print("Yes")