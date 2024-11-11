import re
N,A,B,C,D = (int(x) for x in input().split())
S = input()
if re.search(r'##',S[A-1:max(C,D)]):
    print('No')
else:
    if D < C:
        if re.search(r'\.\.\.',S[B-2:D+2]):
            print('Yes')
        else:
            print('No')
    else:
        print('Yes')