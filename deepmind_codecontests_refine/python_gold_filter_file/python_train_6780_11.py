string = input().strip()
n = int(input().strip())

op_dict = dict()
impossible = True
ctr = 0
for i in range(len(string)):
    if string[i] in ['*','?']:
        ctr += 1
        if string[i] not in op_dict:
            op_dict[string[i]] = [i]
        else:
            op_dict[string[i]].append(i)
str_len = len(string) - ctr
ans = ''
if '*' in op_dict and n >= str_len:
    impossible = False
    to_insert = op_dict['*'][0]
    str_in = ""
    while str_len < n:
        str_in += string[to_insert-1]
        str_len += 1
    temp = string[:to_insert] + str_in + string[to_insert:]
    for i in range(len(temp)):
        if temp[i] not in ["*","?"]:
            ans += temp[i]
elif n == str_len:
    impossible = False
    for i in range(len(string)):
        if string[i] not in ["*","?"]:
            ans += string[i]
elif n >= str_len - ctr and n <= str_len:
    impossible = False
    op_list = []
    for key in op_dict:
        op_list += op_dict[key]
    op_list = set(op_list)
    #op_list.sort()
    for i in range(len(string)):
        if n == str_len:
            if string[i] not in ["*","?"]:
                ans += string[i]
        elif string[i] not in ["*","?"]:
            if i + 1 not in op_list:
                ans += string[i]
            else:
                str_len -= 1

if impossible:
    print('Impossible')
else:
    print(ans)
