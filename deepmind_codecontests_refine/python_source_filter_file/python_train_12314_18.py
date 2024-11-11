from collections import defaultdict
n = int(input())
for i in range(n):
    a = defaultdict(int)
    _ = input()
    for j in list(map(int, input().split())):
        a[j] += 1
    for i in a.values():
        if i > 1:
            print(a)
            print('YES')
            break
    else:
        print('NO')