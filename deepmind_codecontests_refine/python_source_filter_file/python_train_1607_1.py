a1 = input().split()
a = [int(a1[i]) for i in range(len(a1))]
b1 = input().split()
b = [int(b1[i]) for i in range(len(b1))]
if a[0] == b[0] or a[1] == [1] or a[2] == b[2]:
    print('YES')
else:
    print('NO')