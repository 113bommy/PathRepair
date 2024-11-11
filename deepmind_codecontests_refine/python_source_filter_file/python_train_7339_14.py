board = []
for _ in range(8):
    board.append(list(input()))

board = list(map(list,zip(*board)))

b = 8
w = 8

def min_index(l,c):
    for i in range(len(l)):
        if l[i] == c:
            return i

    return len(l) + 1 

for j in range(8):
    ma = min_index(board[j], "W")
    mb = min_index(board[j], "B")
    if ma < mb:
        w = min(w,ma)

for j in range(8):
    ma = min_index(board[j][::-1], "W")
    mb = min_index(board[j][::-1], "B")
    if mb < ma:
        b = min(b,mb)

if w < b:
    print ("A")
else:
    print ("B")