# Stones on the Table, Code forces

num = int(input())
stones = input()
count_R = 0
count_B = 0
count_G = 0
count = 0

for i in stones:

    if i == 'R':
        count_B = 0
        count_G = 0
        count_R += 1

        if count_R >= 2:
            count += 1

    elif i == 'B':
        count_B += 1
        count_R = 0
        count_G = 0

        if count_B >= 2:
            count += 1

    else:
        count_B = 0
        count_R = 0
        count_G += 1

        if count_G >= 2:
            count += 1

print(count)