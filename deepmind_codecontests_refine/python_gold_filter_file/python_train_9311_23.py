from collections import deque
from sys import stdin
lines = deque(line.strip() for line in stdin.readlines())

def nextline():
    return lines.popleft()

def types(cast):
    return tuple(int(x) for x in nextline().split())

def ints():
    return types(int)

def strs():
    return nextline().split()

def main():
    # lines will now contain all of the input's lines in a list
    (n,) = ints()
    nums = ints()
    if n == 1:
        return n
    inc = [1]*n
    for i in range(1, n):
        if nums[i] > nums[i-1]:
            inc[i] = inc[i-1]+1
    dec = [1]*n
    for i in range(n-2, -1, -1):
        if nums[i] < nums[i+1]:
            dec[i] = dec[i+1]+1
    m = max(inc[n-2], dec[1])+1
    for i in range(1, n-1):
        if nums[i-1]+1 < nums[i+1]:
            length = inc[i-1]+dec[i+1]+1
        else:
            length = max(inc[i-1], dec[i+1])+1
        if length > m:
            m = length
    return m

if __name__ == '__main__':
    print(main())
