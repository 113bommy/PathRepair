N = int(input())
h = list(map(int, input().split()))

s = h[0]
for i in range(1, N):
    s += max(0, h[i] - h[i - 1])

print(s)
