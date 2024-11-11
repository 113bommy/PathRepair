try:
    T = int(input())
    for i in range(T):
        N, K = input().split()
        N = int(N)
        K = int(K)
        if N%2==0:
            N=N+(2*K)
        else:
            for j in range(2,N+1):
                if N%j==0:
                    N+=j
                    break
            N=N+(2*(K-1))
    print(N)
except Exception as e:
    print(e)