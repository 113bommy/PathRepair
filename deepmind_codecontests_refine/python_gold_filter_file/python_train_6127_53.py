N, M = map(int, input().split())

S = N
c = M // 2

print(min((S + c) // 2, c))