import sys
input = sys.stdin.readline

def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))


data = list(invr())
row = data[0]
col = data[1]
chips = data[2]

chips *= 2

while chips > 0:
    d = list(invr())
    chips-=1
moves = row+col+row*col-3

print(moves)

for i in range(row-1):
    print('U',end="")

for i in range(col-1):
    print('L',end="")

for i in range(row):
    if i & 1:
        for i in range(col-1):
            print('L',end="")
    else:
        for i in range(col-1):
            print('R',end="")
    if i < row-1:
        print('D',end="")