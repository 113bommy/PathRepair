A, B, C, K = map(int,input().split())
print(min(A, K) + min(0, (A + B) - K ))