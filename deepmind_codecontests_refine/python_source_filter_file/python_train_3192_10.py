n = int(input())
a = input()

flag = 0
for ind, a_i in enumerate(a):
    if ind == 0:
        continue
    else:
        if a_i == a[ind - 1] and a_i != '?':
            flag = 1
            break

if flag == 1:
    print('No')
else:
    if a.count('?') >= 2:
        flag = 0
        for ind, a_i in enumerate(a):
            if ind != 0 and ind != n - 1:
                if a_i == '?' and a[ind - 1] == a[ind + 1] or a_i == '?' and (a[ind - 1] == '?' or a[ind + 1] == '?'):
                    flag = 1
                    break
            elif ind == 0 and a_i == '?' or ind == n - 1 and a_i == '?':
                flag = 1
                break
        print('Yes' if flag == 1 else 'No')
    else:
        if a.count('?') == 0:
            print('Yes')
        else:
            ind = a.index('?')
            if ind == 0 or ind == n - 1:
                print('Yes')
            else:
                if a[ind - 1] == a[ind + 1]:
                    print('Yes')
                else:
                    print('No')

