from sys import stdin, stdout
from bisect import bisect_left
import math

def main():
    n,a,R,m = list(map(int, stdin.readline().split()))
    arr = list(map(int, stdin.readline().split()))
    arr.sort()
    total = 0
    accu = [0] * (n+1)
    for i,x in enumerate(arr):
        total += x
        accu[i] = total
    l=-1
    r=-1
    lowest = 1.e15
    for i,x in enumerate(arr):
        if l == -1:
            l = i
        if i + 1 == len(arr) or arr[i+1] != arr[i]:
            r = i
        if l == -1 or r == -1:
            continue
        add = 0
        if l > 0:
            add= (l * x) - accu[l-1]
        remove = 0
        if r + 1 < len (arr):
            remove = accu[n-1] - accu[r] - ( n - r - 1 ) * x
        move = min(remove ,add)
        res = min( (remove - move)*R + (add - move)*a + m*move, remove*R + add*a )
        lowest = min(lowest, res)
        l = -1
        r = -1
    cal = math.floor(accu[n-1]/n)
    pos = bisect_left(arr,cal)
    if arr[pos] != cal:
        add = (pos * cal) - accu[pos - 1]
        remove = accu[n-1] - accu[pos - 1] - (n - pos) * cal
        move = min(remove ,add)
        res = min( (remove - move)*R + (add - move)*a + m*move, remove*R + add*a )
        lowest = min(lowest, res)
    cal = math.ceil(accu[n-1]/n)
    pos = bisect_left(arr,cal)
    if arr[pos] != cal:
        add = (pos * cal) - accu[pos - 1]
        remove = accu[n-1] - accu[pos - 1] - (n - pos) * cal
        move = min(remove ,add)
        res = min( (remove - move)*R + (add - move)*a + m*move, remove*R + add*a )
        lowest = min(lowest, res)
    stdout.write(str(lowest))
    
main()