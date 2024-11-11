def rolling(s, n):
    l = len(s)
    #右にシフトの場合
    return s[n%l:] + s[:n%l] #左にシフトの場合はnの正負を逆に

def solve():
    N = int(input())
    A = list(map(int,input().split()))
    ans = []
    for i in range(N-1):
        minA = min(A[i:])
        idx = A[i:].index(minA)
        if idx != 0:
            ans.append((i+1,i+idx+1,idx-i))
            A[i:i+idx+1] = rolling(A[i:i+idx+1],idx-i)

    print(len(ans))
    for a in ans:
        print(*a)

Q = int(input())
for _ in range(Q):
    solve()