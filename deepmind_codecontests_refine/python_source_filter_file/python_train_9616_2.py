def wrong_num_index():
    input()
    numbers = [int(elem) for elem in input().split(" ")]
    first_remainder = numbers[0] % 2
    for ind, num in enumerate(numbers[1:]):
        cur_remainder = num % 2
        if cur_remainder != first_remainder:
            if ind == 0:
                next_remainder = numbers[ind + 1] % 2
                return 1 if first_remainder == next_remainder else 2
            else:
                return ind + 2


print(wrong_num_index())
