n = list(map(int, input().split()))
a = set([item for item in range(1, n[1]+1)])
for i in range(n[0]):
     a = a - set(list(map(int, input().split())))
print('YES' if len(a) == 0 else 'NO')
