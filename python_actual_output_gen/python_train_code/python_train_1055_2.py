import sys
input = sys.stdin.buffer.readline

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input()

def listStr():
    return list(input())

def solve():
    N = getInt()
    sum_A = 0
    sum_B = 0
    min_B = 10**9
    for n in range(N):
        a, b = getInts()
        if n > 0:
            y = min(a,prev_b)
            sum_B += y
            min_B = min(min_B,y)
        else:
            first_a = a
        sum_A += a
        prev_b = b
    y = min(first_a,prev_b)
    sum_B += y
    min_B = min(min_B,y)
    return sum_A-sum_B+min_B
    
T = getInt()
for t in range(T):
    print(solve())
