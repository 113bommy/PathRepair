ar = []
for i in range(10):
    ar.append(input())

ans = False

for i in range(10):
    for j in range(10):
        if ar[i][j] == 'X':
            x = 1
            hl = False
            for k in range(1,5):
                if i+k == 10:
                    break
                if ar[i+k][j] == 'X':
                    x += 1
                elif ar[i+k][j] == 'O':
                    break
                elif hl:
                    break
                else:
                    hl = True
                
                if x == 4:
                    if hl:
                        ans = True
                    elif ((i-1>=0)and(ar[i-1][j]=='.'))or((i+k+1<10)and(ar[i+k+1][j]=='.')):
                        ans = True
                    break
            if ans:
                break
            x = 1
            hl = False
            for k in range(1,5):
                if (i+k==10)or(j+k==10):
                    break
                if ar[i+k][j+k] == 'X':
                    x += 1
                elif ar[i+k][j+k] == 'O':
                    break
                elif hl:
                    break
                else:
                    hl = True
                
                if x == 4:
                    if hl:
                        ans = True
                    elif ((i-1>=0)and(j-1>=0)and(ar[i-1][j-1]=='.'))or((i+k+1<10)and(j+k+1<10)and(ar[i+k+1][j+k+1]=='.')):
                        ans = True
                    break
            if ans:
                break
            x = 1
            hl = False
            for k in range(1,5):
                if j+k == 10:
                    break
                if ar[i][j+k] == 'X':
                    x += 1
                elif ar[i][j+k] == 'O':
                    break
                elif hl:
                    break
                else:
                    hl = True
                    
                if x == 4:
                    if hl:
                        ans = True
                    elif ((j-1>=0)and(ar[i][j-1]=='.'))or((j+k+1<10)and(ar[i][j+k+1]=='.')):
                        ans = True
                    break
            if ans:
                break
            x = 1
            hl = False
            for k in range(1,5):
                if (i-k==-1)or(j+k==10):
                    break
                if ar[i-k][j+k] == 'X':
                    x += 1
                elif ar[i-k][j+k] == 'O':
                    break
                elif hl:
                    break
                else:
                    hl = True
                
                if x == 4:
                    if hl:
                        ans = True
                    elif ((i+1<10)and(j-1>=0)and(ar[i+1][j-1]=='.'))or((i-k-1>=0)and(j+k+1<10)and(ar[i-k-1][j+k+1]=='.')):
                        ans = True
                    break
            if ans:
                break
    if ans:
        break
    
if ans:
    print('YES')
else:
    print('NO')

