import math


def decimal_to_binary_conversion(n):
    power = 0
    output_str = ""
    while 2 ** power <= n:
        power += 1
    for i in range(1, power + 1):
        index = power - i
        if n >= 2 ** index:
            output_str += "1"
            n -= 2 ** index
        else:
            output_str += "0"
    return output_str


def binary_to_decimal_conversion(s):
    output = 0
    for i in range(len(s)):
        j = len(s) - 1 - i
        output += 2 ** j * int(s[i])
    return output


def xor_operation(s1, s2):
    difference = max(len(s1), len(s2)) - min(len(s1), len(s2))
    if len(s1) > len(s2):
        s2 = "0" * difference + s2
    else:
        s1 = "0" * difference + s1
    output = ""
    for i in range(len(s1)):
        if s2[i] != s1[i]:
            output += "1"
        else:
            output += "0"
    return output


def main_function():
    output_list = []
    for i in range(int(input())):
        a, b, n = [int(i) for i in input().split(" ")]
        c = binary_to_decimal_conversion(xor_operation(decimal_to_binary_conversion(a), decimal_to_binary_conversion(b)))
        if not n % 3:
            output_list.append(str(a))
        elif n % 3 == 2:
            output_list.append(str(b))
        else:
            output_list.append(str(c))
    return "\n".join(output_list)


print(main_function())