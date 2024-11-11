# cd C:\Users\user\Documents\python done projects

n = int(input())
nums = dict()
while n > 0:
    n -= 1
    fl = False
    m = int(input())
    a = [int(x) for x in input().split()]
    if m < 3:
        print('NO')
        continue
    for i in range(0, m):
        for j in range(i + 1, m):
            if a[j] == a[i] and a[i] != a[j - 1]:
                fl = True
    if fl:
        print('Yes')
    else:
        print('No')
