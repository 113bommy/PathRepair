# import sys

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

def read_line():
    return [int(x) for x in input().split()]

def read_int():
    return int(input())

def solve():
    n = read_int()
    
    res = int(n//10)

    if n%10 == 9:
        res += 1

    print(res)

t = read_int()
# t = 1
while t > 0:
    solve()
    t -= 1