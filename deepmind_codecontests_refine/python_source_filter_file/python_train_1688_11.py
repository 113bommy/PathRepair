import sys

for __ in range(int(input())):
    a = list(input())
    b = list(input())
    A = dict()
    for elem in a:
        if elem in A:
            A[elem] += 1
        else:
            A[elem] = 1
    ans = 'NO'
    for i in range(len(b) - len(a)):
        B = A.copy()
        flag = 0
        for j in range(i, i + len(a)):
            elem = b[j]
            if elem not in B or B[elem] == 0:
                flag = 1
                break
            else:
                B[elem] -= 1
        if flag == 0:
            ans = 'YES'
    print(ans)
