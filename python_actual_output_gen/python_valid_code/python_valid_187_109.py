N, A, B = map(int, input().split())
p = N//(A+B)
print(p*A+N%(A+B))