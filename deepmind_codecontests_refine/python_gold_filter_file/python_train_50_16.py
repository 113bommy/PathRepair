n, m = map(int, input().split())
lst = []
for i in range(n):
    for each in list(map(int, input().split()))[1:]:
        if each not in lst:
            lst.append(each)
if len(lst) == m:
    print('YES')
else:
    print('NO')