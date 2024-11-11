import sys

input = sys.stdin.readline


############ ---- Input Functions ---- ############
def inp():
    return (int(input()))
def inlt():
    return (list(map(int, input().split())))
def insr():
    s = input()
    return (list(s[:len(s) - 1]))
def invr():
    return (map(int, input().split()))


##total sum for any iteration
sum = 10
def solve():
    t = inp()
    while t > 0:
        num = input()
        siz = len(num)
        add = siz*(siz+1)/2
        n_it = (int(num) % 10) - 1
        total = (n_it * sum) + add
        print(total)
        t -= 1
solve()