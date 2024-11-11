N, K = map(int, input().split())
pint("Possible" if N*K*(N+K)%3==0 else "Impossible")