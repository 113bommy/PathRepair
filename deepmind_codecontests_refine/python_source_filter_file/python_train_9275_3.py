from operator import itemgetter
n = int(input())
ai = list(map(int,input().split()))
ai2 = [[ai[i], i] for i in range(n)]
answer = [0] * n
ai2.sort(key = itemgetter(0))
answer[ai2[-1][1]] = 0
answer[ai2[0][1]] = 1
for i in range(n-2,0,-1):
    num = ai2[i][1] % ai2[i][0]
    for j in range(num,n,ai2[i][0]):
        if ai[j] > ai2[i][0] and answer[j] == 0:
            answer[ai2[i][1]] = 1
            break
for i in range(n):
    if answer[i] == 1:
        print("A",end="")
    else:
        print("B",end="")
