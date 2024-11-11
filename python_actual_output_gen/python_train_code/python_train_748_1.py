n = int(input())
A = list(map(int, input().split()))

S = sum(A)
S2 = sum(map(lambda x: x * x, A))

print((S * S - S2 // 2) % (10 ** 9 + 7))
