a, b, k = map(int, input().split())
print([i for i in range(1,101) if a%i+b%i<1][k-1])