N, A, B = map(int, input().split())
print(N*A//(A+B)+min(N%(A+B), A))