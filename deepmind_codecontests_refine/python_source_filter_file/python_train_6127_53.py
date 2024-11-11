N, M = map(int, input().split())
print(max(N+(M-N*2)//4, N))
