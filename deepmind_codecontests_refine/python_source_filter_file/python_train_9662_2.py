N = int(input())
h = [0] + list(map(int, input().split()))

s = 0
for i in range(1, N):
    s += max(0, h[i] - h[i - 1])

print(s)
