a = int(input())
b = int(input())

sum = a + b


def remove_zero_from_number(number_param):
    temp = 0

    len = 1
    while number_param > 0:
        if number_param % 10 != 0:
            temp += (number_param % 10) * (10 ** len - 1)
            len += 1
        number_param //= 10

    return temp


if remove_zero_from_number(a) + remove_zero_from_number(b) == remove_zero_from_number(sum):
    print("YES")
else:
    print("NO")

