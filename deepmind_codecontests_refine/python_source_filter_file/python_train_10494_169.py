N, A, B, C, D = map(int, input().split())
S = input()

flag = True
if "##" in S[A+1:max(C, D)]:
    flag = False
if C > D:
    if "..." not in S[B:D+1]:
        flag = False

if flag:
    print('Yes')
else:
    print('No')