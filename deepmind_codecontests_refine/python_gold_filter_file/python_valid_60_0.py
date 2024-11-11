import sys, copy
input = sys.stdin.readline
def inp():
    return(int(input()))
def inlt():
    return(list(map(int, input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))




t = inp()
for _ in range(t):
    n = inp()
    l = inlt()
    for i in range(len(l) - 1):
        l[i] = l[i] & l[i + 1]
        l[i + 1] = l[i]
    print(min(l))
