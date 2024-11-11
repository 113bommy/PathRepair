s=[]
for i in range(4):
    s.append(input())
for i in range(3):
    for j in range(3):
        t = [s[i][j],s[i][j+1],s[i+1][j],s[i+1][j+1]]
        if t.count('#')!=2:
            print('YES')
            exit(0)
print('NO')