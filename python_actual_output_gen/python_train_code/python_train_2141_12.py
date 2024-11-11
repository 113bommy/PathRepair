a = [int(i) for i in input().split()]
s = sum(a)
if s % 2 != 0:
    for i in range(4):
        for j in range(i + 1, 5):
            for k in range(j + 1, 6):
                if a[i] + a[j] + a[k] == s // 2:
                    print("YES")
                    exit(0)
print('NO')
