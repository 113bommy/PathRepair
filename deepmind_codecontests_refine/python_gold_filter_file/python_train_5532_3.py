t = input()
num = str(t)
lucky_num_4 = num.count('4')
lucky_num_7 = num.count('7')
a = lucky_num_4+lucky_num_7
if a==4 or a==7:
    print('YES')
else:
    print('NO')