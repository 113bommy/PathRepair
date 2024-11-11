N, K = map(int, input().split())

C = N-K+1
D = 1
for i in range(1, K+1):
    if N-K+1 < i:
        print(0)
    else:
        ans = (int(C*D))%(10**9+7)
        print(ans)
    #print(C,D)
    C = C*(N-K-i+1)/(i+1)
    D = D*(K-i)/i
