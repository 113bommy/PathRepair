N = int(input())
V = list(map(int, input().split()))
C = list(map(int, input().split()))

W = [v-c for v, c in zip(V, C) if (v-c) > 0]
print(sum(W)