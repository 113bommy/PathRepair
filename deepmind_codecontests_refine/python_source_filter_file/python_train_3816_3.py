r,c = map(int,input().split())
l = []
for i in range(r):
    l.append(input().replace('.','D'))
flag = True
for i in range(r):
    for j in range(c-1):
        if(i ==0):
            if((l[i][j] == 'S' and l[i][j+1] == 'W') or (l[i][j] == 'W' and l[i][j+1] == 'S')):
                flag = False
                break
        else:
            if((l[i][j] == 'S' and l[i][j+1] == 'W') or (l[i][j] == 'W' and l[i][j+1] == 'S')):
                flag = False
                break
            elif((l[i-1][j] == 'S' and l[i][j] == 'W') or (l[i-1][j] == 'W' and l[i][j] == 'S')):
                flag = False
                break
            elif((l[i-1][j+1] == 'S' and l[i-1][j+1] == 'W') or (l[i-1][j+1] == 'W' and l[i-1][j+1] == 'S')):
                flag = False
                break
if(flag == False):
    print("No")
else:
    print("Yes")
    for i in l:
        
        print(i)

