n = int(input())
S = set()
for i in range(1, 30):
    s = i*(i+1)//2
    S.add(s)
if n in S:
    print('YES')
else:
    print('NO')
