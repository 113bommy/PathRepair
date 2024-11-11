N, x = map(int, input().split())
if x in (1, 2*N-1):
    print('No')
else:
    print('Yes')

    ans = list(range(1, 2*N-1))[x-N:]+list(range(1, 2*N-1))[:x-N]
    print(*ans, sep='\n')
