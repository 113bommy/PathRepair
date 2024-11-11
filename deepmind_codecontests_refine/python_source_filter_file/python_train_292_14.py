N = int(input())
p = list(map(int, input().split()))
p.insert(0, -1)

j = [0] * N
for i in range(1, N + 1):
    if p[i] == i and j[i - 1] == 0:
        j[i] = 1
print(sum(j))