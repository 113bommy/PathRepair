n = int(input())
s = input()
o = ['0']*10
for i in s:
    if i == 'L':
        j = 0
        while j < 10:
            if o[j] == '1':
                j += 1
            else:
                o[j] = '1'
                break
    elif i == 'R':
        j = 1
        while j < 11:
            if o[-j] == '1':
                j += 1
            else:
                o[-j] = '1'
                break
    else:
        o[int(i)] = '0'
print(''.join(map(str, o)))
