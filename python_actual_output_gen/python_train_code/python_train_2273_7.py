n = int(input())

M = []
for i in range(n):
    M.append(list(input().strip()))
    
count = 0
for i in range(1,n-1):
    for j in range(1,n-1):
        if M[i][j] == 'X' and M[i-1][j-1] == 'X' and M[i+1][j-1] == 'X' and M[i+1][j-1] == 'X' and M[i+1][j+1] == 'X':
            count += 1

print(count)