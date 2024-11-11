def string_split(s, a):
    output_list = []
    intermediate_str = ""
    for loc, i in enumerate(s):
        if i != a:
            intermediate_str += i
            if loc == len(s) - 1:
                output_list.append(int(intermediate_str))
        else:
            if len(intermediate_str) != 0:
                output_list.append(int(intermediate_str))
                intermediate_str = ""
    return output_list





def func():
    a = input()
    output_str = ""
    for i in range(int(a)):
        b = input()
        n, x = string_split(b, " ")
        first_flat_numb = 1
        floor = 1
        if n == 1 or n == 2:
            output_str += str(floor) +"\n"
        else:
            while n > first_flat_numb:
                floor += 1
                first_flat_numb = (floor - 2) * x + 3
            output_str += str(floor - 1) + '\n'
    return output_str[:-1]


print(func())