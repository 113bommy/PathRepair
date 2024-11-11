n = input()
z_cnt = 0
flag = 0
if n[0] == '0':
        for x in n:
                if x == '0' and flag == 0:
                        z_cnt += 1
                else:
                        flag = 1
        n = z_cnt * '0' + n
else:
        n = n[::-1]
        for x in n:
                if x == '0' and flag == 0:
                        z_cnt += 1
                else:
                        flag = 1
        n = n + z_cnt * '0'
print(n)
i = n[::-1]
if i == n:
        print('YES')
else:
        print('NO')
