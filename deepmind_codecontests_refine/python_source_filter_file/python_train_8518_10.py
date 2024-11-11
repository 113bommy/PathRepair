S = input()
if len(S) > 9:
    print('NO')
    exit()

if S.replace('A', '') != 'KIHBR':
    print('NO')
    exit()

for i in range(1, len(S)):
    if S[i] == 'A' and S[i-1] not in ('H', 'B', 'R'):
        print('No')
        exit()

print('YES')
