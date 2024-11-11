
class Chess_board:
    def __init__(self):
        self.board=[[0]*8 for i in range(8)]
        self.queen_array=[]
        self.queen_row=[]


def copy_board(chess_board):
    new_board=Chess_board()
    new_board.board=[chess_board.board[i][:] for i in range(8)]
    new_board.queen_array=chess_board.queen_array[:]
    new_board.queen_row=chess_board.queen_row[:]
    return new_board


def mk_board(chess_board,queen_array):
    for queen in queen_array:
        row=queen[0]
        col=queen[1]
        if(chess_board.board[row][col]==0):
            chess_board.queen_array.append(queen)
            chess_board.queen_row.append(row)
            for i in range(8):
                chess_board.board[row][i]=1
            for i in range(8):
                chess_board.board[i][col]=1
            for i in range(1,8):
                if(row - i >=0 and col - i >=0):
                    chess_board.board[row-i][col-i]=1
                else:
                    break
            for i in range(1,8):
                if(8 > row + i >=0 and col - i >=0):
                    chess_board.board[row+i][col-i]=1
                else:
                    break
            for i in range(1,8):
                if(row - i >=0 and 8 > col + i >=0):
                    chess_board.board[row-i][col+i]=1
                else:
                    break
            for i in range(1,8):
                if(8 > row + i >=0 and 8 > col + i >=0):
                    chess_board.board[row+i][col+i]=1
                else:
                    break

        else:
            return 0
    
    return 1



def find_queen(chess_board):
    
    for tmp_row in range(8):
        if(tmp_row in chess_board.queen_row):
            pass
        else:
            break
    
    for col in range(8):
        new_board=copy_board(chess_board)
        if(mk_board(new_board,[[tmp_row,col]])==1):
            if(len(new_board.queen_row)==8):
                return new_board
            else:
                result=find_queen(new_board)
                if(result is not None):
                    return result
    
    return None



n=int(input())

queen_array=[]
for i in range(n):
    queen_array.append(list(map(int,input().split())))

board=Chess_board()
mk_board(board,queen_array)
if(n==8):
    result_board=find_queen(board)
else:
    result_board=board

for i in range(8):
    for queen in result_board.queen_array:
        if(queen[0]==i):
            str1="."*queen[1]
            str2="."*(7-queen[1])
            print(f"{str1}Q{str2}")
