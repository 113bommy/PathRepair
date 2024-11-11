n = int(input())
A = list(map(int, input().split()))

s = []
for a in A:
    if s:
        if s[-1]%2 == a%2:
            s.pop()
        else:
            s.append(a)
    else:
        s.append(a)
if len(s) > 2:
    print('NO')
else:
    print('YES')
