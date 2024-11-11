import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    D, M = map(int, input().split())
    L = []
    rem = D
    for i in range(40):
        n = 1<<i
        n = min(n, rem)
        L.append(n)
        rem -= n
        if rem==0:
            break
    #print(L)
    ans = 1
    for l in L:
        ans = ans * (l+1) % M
    print((ans-1)%M)
