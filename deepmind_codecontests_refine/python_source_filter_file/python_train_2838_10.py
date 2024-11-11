num = int(input())
for i in range(num):
    quest = input().split()
    numbers = [int(i) for i in quest]
    if (
        (numbers[0] > numbers[1] and numbers[0] > numbers[2])
        or (numbers[1] > numbers[0] and numbers[1] > numbers[2])
        or (numbers[2] > numbers[0] and numbers[2] > numbers[1])
    ):
        print("NO")
        continue
    else:
        print("YES")
        if numbers[0] == numbers[1] and numbers[1] == numbers[2]:
            print(numbers[0], numbers[0], numbers[0])
        elif numbers[0] == numbers[1]:
            print(numbers[0], numbers[1], numbers[1])
        elif numbers[1] == numbers[2]:
            print(numbers[0], numbers[0], numbers[2])
        else:
            print(numbers[0], numbers[1], numbers[1])
