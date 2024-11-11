from collections import Counter, deque

N = int(input())
A = deque(map(int, input().split()))
B = deque(map(int, input().split()))

ca, cb = Counter(A), Counter(B)

cab = ca+cb

if any(c > N for c in cab.values()):
    print('No')
else:
    print('Yes')
    B.reverse()
    res = []
    while A:
        if A[0] != B[0]:
            A.popleft()
            res.append(str(B.popleft()))
        else:
            B.rotate()
        
    print(' '.join(res))