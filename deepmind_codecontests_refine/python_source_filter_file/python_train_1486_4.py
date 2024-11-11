n, m = [int(i) for i in input().split()]

matrix = ["" for i in range(n)]

for i in range(n):
    matrix[i] = input()
    
if n > 4: print(-1)
elif n == 1: print(0)
elif n == 2:
    ps = 0
    ptl = 0
    
    for i in range(m):
        if (int(matrix[0][i])+int(matrix[1][i])) % 2 == i % 2: ps +=1
        else: ptl += 1
            
    print(min([ps, ptl]))
else:
    ans = [[m, m], [m, m]]
    
    for i in range(m):
        up = (int(matrix[0][i])+int(matrix[1][i]))%2
        down = (int(matrix[1][i])+int(matrix[2][i]))%2
        
        if down == i%2:
            if up == i%2: ans[0][0] -= 1
            else: ans[0][1] -= 1
        else:
            if up == i%2: ans[1][0] -= 1
            else: ans[1][1] -= 1
    
    final = min([min(ans[0]), min(ans[1])])
    print(final)