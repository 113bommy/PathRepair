N, A, B = map(int,input().split())
print(A*(N//(A+B)) + max(N%(A+B), 0))