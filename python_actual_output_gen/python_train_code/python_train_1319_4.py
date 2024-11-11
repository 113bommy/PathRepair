y,x=map(int,input().split())
m=[['D']*x]
for i in range(y):
    m.append(list(input().replace('.','D')))
    j=0
    for j in range(x-1):
        s=m[i][j]+m[i+1][j]+m[i+1][j+1]
        if 'SW' in s or 'WS'in s:
            print('NO')
            break
    else:
        j+=1
        s=m[i][j]+m[i+1][j]
        if s in 'sws':
            print('NO')
            break
        continue
    break
else:
    print('YES')
    for line in m[1:]:
        print(''.join(line))
