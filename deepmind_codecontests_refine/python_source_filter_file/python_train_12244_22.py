n, k = map(int, input().split())
s = input()
good = True
for x in s:
    if s.count(x) != k:
        good = False
        break
if good:
    print('Yes')
else:
    print('NO')