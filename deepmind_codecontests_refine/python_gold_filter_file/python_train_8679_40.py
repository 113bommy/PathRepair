# import sys

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

def read_array():
    return [int(x) for x in input().split()]

def read_int():
    return int(input())

def solve():
    n = read_int()
    a = read_array()

    ct = [0 for _ in range(3002)]

    for x in a:
        ct[x] += 1
    
    for i in range(1, 3002):
        if ct[i] == 0:
            print(i)
            return;

# t = read_int()
t = 1
while t > 0:
    solve()
    t -= 1