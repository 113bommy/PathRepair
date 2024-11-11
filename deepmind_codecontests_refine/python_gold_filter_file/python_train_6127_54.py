N, M = map(int, input().split())
print(min(N+(M-N*2)//4, M//2))
