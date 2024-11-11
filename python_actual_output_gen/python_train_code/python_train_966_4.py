import sys
sp1 = ['1','4','7']
sp2 = ['1','2','3']
sp3 = ['3','6','9']
sp4 = ['7','0','9']
n = int(input())
s = input()
for i in sp1:
    if i in s:
        if '0' in s:
            print('YES')
            sys.exit(0)
        else:    
            for j in sp2:
                if j in s:
                    for k in sp3:
                        if k in s:
                            for t in sp4:
                                if t in s:
                                    print('YES')
                                    sys.exit(0)
else:
    print('NO')
