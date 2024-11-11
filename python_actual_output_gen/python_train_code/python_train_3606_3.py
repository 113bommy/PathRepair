N, A, B, C, D = map(int, input().split())
Sp = input()

if Sp[A-1:max([C, D])].find('##') != -1:
    print('No')
    exit()

if C < D:
    print('Yes')
    exit()

if Sp[B-2:D].find('...') >= 0:
    print('Yes')
else:
    print('No')