__author__ = 'Suvasish'

lst = []
a_row = 7
b_row = 0
b_lst = []
a_lst = []

for i in range(0, 8):
    lst.append(list(input()))
    # print(lst[i])
    if 'W' in lst[i]:
        a_lst.append(i)

    if 'B' in lst[i]:
        b_lst.append(i)

b_lst.reverse()
# print('AL', a_lst)
# print('BL', b_lst)
_break = False
for i in a_lst:
    if _break:
        break
    for l in range(0, 8):
        if _break:
            break
        # Checking for the position of 'W'
        if lst[i][l] == 'W':
            # check earlier columns if the position of 'W' is blocked or not.
            for j in range(0, i):
                # print('I:', i)
                # print('J:', j, '---', 'JL_VAL:', lst[j][l])
                if 'B' in lst[j] and lst[j][l] == 'B':
                    break
                else:
                    if j == i:
                        a_row = i
                        _break = True
                        break
# print('A_ROW:', a_row)
_break = False
for k in b_lst:
    # print('B_K: ', k)
    if _break:
        break
    for m in range(0, 8):
        if _break:
            break
        if lst[k][m] == 'B':
            for n in range(k+1, 8):
                # print('M: ', m)
                if 'W' in lst[n] and lst[n][m] == 'W':
                    break
                else:
                    if n == 7:
                        b_row = k
                        _break = True
                        break
# print('B_ROW:', b_row)

if (7-b_row) < a_row:
    print('B')
else:
    print('A')