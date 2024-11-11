i = int(input())
s = input().split()

l = []
for j in s:
    if not l or  int(j)%2 != l[-1]:
        l.append(int(j)%2)
    else:
        l.pop()

if len(l) < 2:
    print('YES')
else:
    print('NO')


