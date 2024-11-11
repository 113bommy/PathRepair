s = input().split()
if s[2] == 'week':
    print(53 if int(s[0]) in [5,6] else 52)
else:
    print(7 if int(s[0]) == 31 else 11 if int(s[0]) in [29,30] else 12)

