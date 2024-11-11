Q, H, S, D = map(int, input().split())
N = int(input())
Q *= 4
H *= 2
S = min(Q, H, S)
print(N // 2 * min(2 * S, D) + S)