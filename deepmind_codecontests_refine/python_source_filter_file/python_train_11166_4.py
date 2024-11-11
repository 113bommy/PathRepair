from collections import defaultdict

for _ in range(int(input())):
    n = int(input())
    A = input()
    B = input()
    ls = defaultdict(list)
    flag = 0
    for i in range(n):
        if A[i] != B[i]:
            ls[B[i]].append(i)
    if A[i] > B[i]:
        flag = 1
    if flag == 1:
        print(-1)
        continue
    else:
        for i in ls:
            ls[i] = sorted(ls[i], key=lambda x: A[x])
        lst = sorted(ls.keys())
        res = 0
        for i in lst:
            for j in ls[i]:
                if A[j] != B[j]:
                    res += 1
                    A = A.replace(A[j], B[j])
        print(res)

        