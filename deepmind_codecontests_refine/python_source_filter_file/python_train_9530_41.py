n = int(input())

flag = False
for i in range(n):

    s, before, after = input().split()
    before, after = int(before), int(after)
        
    if (after - before) > 0 and before > 2400:
        flag = True
        break

if flag:
    print('YES')
else:
    print('NO')