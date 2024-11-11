N, K = map(int, input().split())
H = sorted([int(x) for x in input().split()])[::-1]
print(sum(H[N:]))
