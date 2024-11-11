n = int(input())

ans = [[0 for i in range(n)] for j in range(n)]

ans_for_4 = [[8, 9, 1, 13], [3, 12, 7, 5], [0, 2, 4, 11], [6, 10, 15, 14]]

for i in range(n):
    for j in range(n):
        ans[i][j] = ans_for_4[i%4][j%4] + (i//4) + (n//4)*(j//4)
        
for i in range(n):
    print(" ".join([str(j) for j in ans[i]]))
        