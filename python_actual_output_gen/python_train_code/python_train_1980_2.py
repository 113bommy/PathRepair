


def solve(N,K):
    if K > (N-1)//2:
        print(-1)
        return

    def it():

        for i in range((N+1)//2):
            yield (K+i, K+N+i+N//2, K+N*2+i*2)
        for i in range(N//2):
            yield (K+(N+1)//2 + i, K+N+i, K+N*2+i*2+1)

    for a,b,c in it():
        print(a,b,c)

N,K = map(int,input().split())
solve(N,K)