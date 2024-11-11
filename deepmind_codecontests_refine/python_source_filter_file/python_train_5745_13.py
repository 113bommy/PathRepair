T = int(input())
for _ in range(T):
    N,M,K = map(int,input().split())
    H = list(map(int,input().split()))
    if N==1:
        print('YES')
        continue
    for a,b in zip(H,H[1::]):
        if a+M < b-K:
            print('NO')
            break
        elif a < b-K:
            M -= b-K - a
        else:
            M += max(a, a - (b-K))
    else:
        print('YES')
