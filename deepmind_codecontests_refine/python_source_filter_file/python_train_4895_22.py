N = int(input())
max_p = -114514
min_v = int(input())
for i in range(1, N):
    R = int(input())
    max_p = max(R - min_v, max_p)
    min_v = min(R, min_v)

print(max_p)