n = int(input())
s = list(map(int, input().split()))

non_good_numbers = []
raw_numbers = []
for i in s:
    count = s.count(i)
    if count == 1:
        raw_numbers.append(i)
    elif (count % 2) == 1:
        non_good_numbers.append(i)
if (len(raw_numbers) % 2) == 1 and (len(non_good_numbers) == 0):
    print('NO')
else:
    if (len(raw_numbers) % 2) == 1:
        use_non_good_number = non_good_numbers[0]
    else:
        use_non_good_number = None
    is_non_good_used = False
    res = []
    number_flag = 'A'
    for i in s:
        if i == use_non_good_number:
            if not is_non_good_used:
                res.append('B')
                is_non_good_used = True
            else:
                res.append('A')
        else:
            if i in raw_numbers:
                res.append(number_flag)
                number_flag = 'B' if number_flag == 'A' else 'A'
            else:
                res.append('A')

    print('YES')
    print(''.join(res))
