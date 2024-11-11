a,b = list(map(int,input().split()))
ls = [['#']*99 for i in range(49)] + [['.']*99 for i in range(49)]
i,j = 0,0
for c in range(a - 1):
    ls[i][j] = '.'
    if j >= 97:
        j = 0;i += 2
    else:
        j += 2
i,j = 51,0
for c in range(b - 1):
    ls[i][j] = '#'
    if j >= 97:
        j = 0;i += 2
    else:
        j += 2
print(98,99)
for j in range(98):
    print(''.join(ls[j]))