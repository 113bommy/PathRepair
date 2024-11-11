import itertools
n = int(input())
A = [[] for i in range(n)]
for i in range(n):
    a = list(map(int, input().split()))
    A[i] = a

if n == 1:
    num = 1
    for i in range(10):
        if num not in A[0]:
            break
        num += 1
    print(num - 1)
elif n == 2:
    num = 1
    while num in A[0] or num in A[1]:
        num += 1
    if num == 10:
        while ((num // 10) in A[0] and (num % 10) in A[1]) \
                or ((num // 10) in A[1] and (num % 10) in A[2]):
            num += 1

    print(num)
else:
    num = 1
    while num in A[0] or num in A[1] or num in A[2]:
        num += 1
    if num == 10:
        R = [0, 1, 2]
        while True:
            flag = False
            for i, j in list(itertools.combinations(R, 2)):
                if (num // 10) in A[i] and (num % 10) in A[j] or (num // 10) in A[j] and (num % 10) in A[i]:
                    flag = True
            if not flag:
                break
            else:
                num += 1

    print(num - 1)