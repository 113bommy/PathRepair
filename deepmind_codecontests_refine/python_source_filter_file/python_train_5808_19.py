# -*- coding: utf-8 -*-
n, a, b, c = map(int, input().split())

value_dict = {'A': a, 'B': b, 'C': c}
result_list = []
input_list = []
flag = True

for i in range(n):
    input_list.append(input())

for next, input in enumerate(input_list, 1):
    if value_dict[input[0]] < value_dict[input[1]]:
        value_dict[input[0]] += 1
        value_dict[input[1]] -= 1
        result_list.append(input[0])
    elif value_dict[input[1]] < value_dict[input[0]]:
        value_dict[input[1]] += 1
        value_dict[input[0]] -= 1
        result_list.append(input[1])
    else:
        if value_dict[input[0]] == 0:
            flag = True
            break
        elif next == len(input_list):
            result_list.append(input[0])
        elif input[0] in input_list[next]:
            value_dict[input[0]] += 1
            value_dict[input[1]] -= 1
            result_list.append(input[0])
        else:
            value_dict[input[1]] += 1
            value_dict[input[0]] -= 1
            result_list.append(input[1])

if flag:
    print('Yes')
    for result in result_list:
        print(result)

else:
    print('No')
