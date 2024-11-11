import sys
input = sys.stdin.readline

'''

'''

n, k = map(int, input().split())

from collections import deque

def powers_of_two(n):
    b = bin(n)[2::]
    dq = deque()
    for i, c in enumerate(reversed(b)):
        if c == "1":
            dq.append(2**i)
    return dq

def solve(n, k):
    if k > n:
        return []
    elif k == n:
        return [0] * n

    dq = powers_of_two(n)
    length = len(dq)
    while length < k:
        cur = dq.pop()
        a = cur // 2

        if a == 1:
            dq.appendleft(1)
            dq.appendleft(1)
        else:
            dq.append(a)
            dq.append(a)
        
        length += 1
    
    return dq if length == k else []

res = solve(n, k)

if not res:
    print("NO")
else:
    print("YES")
    print(*res)