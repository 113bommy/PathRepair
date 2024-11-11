import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

if N == 1:
    ans = A
else:
    dp1 = [0]*N
    bit = 0
    for i, a in enumerate(A):
        bit |= a
        dp1[i] = bit

    dp2 = [0]*N
    bit = 0
    for i in reversed(range(N)):
        bit |= A[i]
        dp2[i] = bit

    score = -1
    ind = -1
    for i in range(N):
        if i == 0:
            tmp = dp2[1]
        elif i == N-1:
            tmp = dp1[N-2]
        else:
            tmp = dp1[i-1]|dp2[i+1]
        if A[i]|tmp-tmp > score:
            score = A[i]|tmp-tmp
            ind = i
    ans = [A[ind]]
    for i, a in enumerate(A):
        if i != ind:
            ans.append(a)
print(*ans, sep=" ")