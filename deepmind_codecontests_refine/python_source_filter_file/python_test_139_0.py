n = int(input())

arr = []
for i in range(n):
    arr.append(input())

for st in arr:
    l = len(st)
    if l % 2 == 0:
        print(st[0:l//2] , st[l//2:])
        if st[:l//2] == st[l//2:]:
            print('YES')
        else:
            print('NO')
    else:
        print('NO')
