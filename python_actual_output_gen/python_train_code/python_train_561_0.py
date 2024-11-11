n = int(input())
a = list(map(int, input().split()))
aset = set(a)
if len(a) == 1:
    print(' '.join(map(str, a)))
else:
    count = [-1, -1]
    for elem in a:
        count[elem - 1] += 1
    print(2, 1, end = ' ')
    for i in range(count[1]):
        print(2, end = ' ')
    for i in range(count[0]):
        print(1, end = ' ')