import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp(): #Integer
    return(int(input()))
def inlt(): #integer list
    return(list(map(int,input().split())))
def insr(): #String
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

board = inlt()
boardSize =board[0]*board[1]

print((boardSize-boardSize%2 )/ 2)
