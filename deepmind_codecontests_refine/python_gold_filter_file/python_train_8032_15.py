
h, w = map(int, input().split())
mat = [input() for _ in range(h)]

num_row = [sum(c=='*' for c in mat[i]) for i in range(h)]
total = sum(num_row)

x = -1
y = -1
for i in range(1, h-1):
    for j in range(1, w-1):
        if(mat[i][j] == '*' 
            and mat[i+1][j] == '*'
            and mat[i-1][j] == '*'
            and mat[i][j+1] == '*'
            and mat[i][j-1] == '*'):
            x = i
            y = j
            break
if x== -1:
    print("NO")
    exit()

cross = 1
for xx in range(x+1, h):
    if mat[xx][y] == '*':
        cross += 1
    else:
        break
for xx in range(x-1, -1, -1):
    if mat[xx][y] == '*':
        cross += 1
    else:
        break
for yy in range(y+1, w):
    if mat[x][yy] == '*':
        cross += 1
    else:
        break
for yy in range(y-1, -1, -1):
    if mat[x][yy] == '*':
        cross += 1
    else:
        break

print('YES' if total == cross else 'NO')

