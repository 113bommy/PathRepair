num_test = int(input())

def solve():
    n, m = map(int, input().split())
    bList = [[0] * (m+1)]
    for i in range(n):
        bList.append( [0] + list(input()) )
    ansNum = 0
    ansList = []
    for i in range(1, n+1):
        for j in range(1, m+1):
            if bList[i][j] == 0:
                continue

            ansNum += 3
            dx = 1; dy = 1
            if i == n:
                dx = -1
            if j == m:
                dy = -1
            ansList.append(sorted([[i, j], [i+dx, j], [i+dx, j+dy]]))
            ansList.append(sorted([[i, j], [i, j+dy], [i+dx, j+dy]]))
            ansList.append(sorted([[i, j], [i, j+dy], [i+dx, j]]))

    print(ansNum)
    for ans in ansList:
        for i, j in ans:
            print(i, j, end = " ")
        print()

for i in range(num_test):
    solve()