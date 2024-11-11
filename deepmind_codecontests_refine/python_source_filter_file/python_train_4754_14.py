def findScore(board,num):
    stones = board[num]
    div = int(stones/12)
    mod = int(stones%12)
    board[num] = 0
    for i in range(len(board)):
        if i < mod:
            board[int((num+i+1)%12)] += div + 1
        else:
            board[int((num+i+1)%12)] += div

    score = 0
    for i in board:
        if i%2 == 0:
            score += i
    return score

board1 = input().split(' ')
board=[]
for i in board1:
    board.append(int(i))
maxScore = 0
for i in range(len(board)):
    if board[i] > 0:
        maxScore = max(maxScore,findScore(board[:],i))

print(maxScore)
