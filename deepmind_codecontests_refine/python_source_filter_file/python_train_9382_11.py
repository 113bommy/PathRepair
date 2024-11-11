i = int(input())
s = input().split()

l = []
for j in s:
    if not l or  int(j) != l[-1]:
        l.append(int(j))
    else:
        l.pop()

if len(l) < 2:
    print('YES')
else:
    print('NO')


