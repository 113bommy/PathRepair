import math

n = int(input())
s = input()

if s[0] == 'W' or s[-1] == 'W':
    print(0)
else:    
    s_lr = 'L'
    for i in range(len(s)-1):
        if s[i+1] == s[i]:
            if s_lr[-1] == 'L':
                s_lr += 'R'
            else:
                s_lr += 'L'
        else:
            if s_lr[-1] == 'L':
                s_lr += 'L'
            else:
                s_lr += 'R'    
    l_cnt = 0
    r_cnt = 0
    lst = []
    for i in s_lr:
        if i == 'L':
            l_cnt += 1
            lst.append(0)
        else:
            if l_cnt - r_cnt <= 0:
                print(0)
                break
            else:
                lst.append(l_cnt - r_cnt)
            r_cnt += 1
    else:
        if l_cnt != r_cnt:
            print(0)
        else:
            res = 1
            for i in lst:
                if i > 0:
                    res = res % (10**9 + 7)
            print(res * math.factorial(n) % (10**9 + 7) )