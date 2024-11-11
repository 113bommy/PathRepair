N, A, B = map(int, input().split())

print(N//(A+B)*B + max(N%(A+B)-A, 0))
