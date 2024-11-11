N, K = list(map(int, input().rstrip()))
ans = K * (K-1)**(N-1)
print(ans)