

def main(length, arr):
    pass
    # first          = 100101
    # second         = 111001
    # first & second = 100001
    # first ^ second = 011110

    # result of & operation is bigger only in case when both of first digits of both numbers in binary form are 1
    # otherwise it's less. It's possible when length of binary forms of both digits are equal.
    # So, we count number of numbers with same length in binary form for each length
    # And number of pairs will be number of combinations of elements in group by 2

    groups_sizes = {}
    result = 0
    for number in arr:
        binary_form = "{0:b}".format(number)
        value = groups_sizes.get(len(binary_form), 0)

        groups_sizes[len(binary_form)] = value + 1

    for key in groups_sizes:
        value = groups_sizes[key]

        sub_result = (value * (value - 1)) // 2
        result += sub_result

    return result


if __name__ == "__main__":
    tt = int(input())

    for _ in range(tt):
        length = int(input())

        arr = list(map(int, input().split(" ")))
        print(main(length, arr))

