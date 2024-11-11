import sys
import math

#to read string
get_string = lambda: sys.stdin.readline().strip()
#to read list of integers
get_int_list = lambda: list( map(int,sys.stdin.readline().strip().split()) )
#to read integers
get_int = lambda: int(sys.stdin.readline())

#--------------------------------WhiteHat010--------------------------------------#
n = get_int()
s = list(get_string())
if n%4 == 0:
    d = {
        'A': n//4,
        'G': n//4,
        'C': n//4,
        'T': n//4
    }

    flag = True
    for i,v in d.items():
        if v > s.count(i):
            flag = False
            break
    if flag:
        for ele in s:
            if ele != '?':
                d[ele] -= 1
        res = ''
        for i,v in d.items():
            res += i*d[i]  
        i = 0
        for j in range(n):
            if s[j] == '?':
                s[j] = res[i]
                i += 1
        print(''.join(s))
    else:
        print('===')
else:
    print('===')