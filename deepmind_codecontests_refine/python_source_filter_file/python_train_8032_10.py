n, m = [int(x) for x in input().split()]

a = [[0] * m for i in range(n)]

for i in range(n):
    a[i] = input()
    
x = -1
y = -1   
    
for i in range(1, n-1):
    for j in range(1, m-1):
        if(a[i][j]=='*' and a[i-1][j]=='*' and a[i][j-1]=='*' and a[i+1][j]=='*' and a[i][j+1]=='*'): 
            x = j
            y = i
    
if x==-1 and y==-1:
    print("NO")
    quit()
    
for i in range(x, m):
    if a[y][i] == '.': break
    a[y] = a[y][:i] + '.' + a[y][i+1:]
    
a[y] = a[y][:x] + '*' + a[y][x+1:]

for i in range(x, 0, -1):
    if a[y][i] == '.': break
    a[y] = a[y][:i] + '.' + a[y][i+1:]
    
 
a[y] = a[y][:x] + '*' + a[y][x+1:]

for i in range(y, n):
    if a[i][x] == '.': break
    #print(i, x)
    a[i] = a[i][:x] + '.' + a[i][x+1:]
    
a[y] = a[y][:x] + '*' + a[y][x+1:]

for i in range(y, 0, -1):
    if a[i][x] == '.': break
    a[i] = a[i][:x] + '.' + a[i][x+1:]
'''
for i in range(n):
    for j in range(m):
        print(a[i][j], end = '')
    print()
'''

for i in range(n):
    for j in range(m):
        if(a[i][j]=='*'):
            print("NO")
            quit()

print("YES")
    

    

    