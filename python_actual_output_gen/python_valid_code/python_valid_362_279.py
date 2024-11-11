name = 'amsn'
lst = []
for i in name:
    if i in lst:
        continue
    else:
        lst.append(i)
if len(lst) % 2 == 0:
    print('CHAT WITH HER!')
else:
    print('IGNORE HIM!')