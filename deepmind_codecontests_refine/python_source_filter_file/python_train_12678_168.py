N, A, B= map(int, input().split())

print(A*N//(A+B)+min(N%(A+B), A))