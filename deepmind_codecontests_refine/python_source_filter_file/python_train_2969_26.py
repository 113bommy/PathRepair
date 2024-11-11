str = list(input().split())
months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
weeks = [52, 52, 52, 52, 52, 52, 53]
if str[2] == 'week':
    print(weeks[int(str[0]) - 1])
else:
    cnt = 0
    for days in months:
        if days >= int(str[0]):
            cnt += 1
    print(cnt)
