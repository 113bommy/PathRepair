from sys import stdin
from sys import stdout

def readdata():
    global a, b, c
    a, b, c = [int(x) for x in stdin.readline().split()]
    
    
def solve():
    for x in range(a + 1):
        z = a - x
        y = b - x
        if y + z == c and y >= 0 and z >= 0:
            print(x, y, z)
            return
    print('impossible')


readdata()
solve()