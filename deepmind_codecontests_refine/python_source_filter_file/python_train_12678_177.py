N,A,B = list(map(int, input().split()))
print(N//(A+B)*A + min(N%(A+B), B))