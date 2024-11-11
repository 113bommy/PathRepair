num = int(input())
grades = sorted(list(map(int, input().split())))
counter = 0
if sum(grades) / num < 4.5:
    while sum(grades) / num <= 4.5:
        if grades[counter] != 5:
            grades[counter] += 1
            counter += 1
        else:
            counter = 0
    print(counter)
else:
    print(counter)