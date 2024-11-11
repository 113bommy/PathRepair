n = int(input())
ai = list(map(int,input().split()))
ai2 = [[0]*n for i in range(2)]
ai2[ai[0] < 0][0] = 1
for i in range(n):
    if ai[i] < 0:
        ai2[0][i] = ai2[1][i-1]
        ai2[1][i] = ai2[0][i-1] + 1
    else:
        ai2[0][i] = ai2[0][i-1] + 1
        ai2[1][i] = ai2[1][i-1]
print(sum(ai2[1]),sum(ai2[0]))
    
