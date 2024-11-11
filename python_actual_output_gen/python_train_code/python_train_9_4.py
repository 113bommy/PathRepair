from itertools import permutations

r1, r2 = list(map(int, input().split()))
c1, c2 = list(map(int, input().split()))
d1, d2 = list(map(int, input().split()))


for i, j, k, l in permutations(range(1, 10), 4):
    if i + j == r1 and k + l == r2 and i+l == c1 and j+k == c2 and i+k == d1 and j + l == d2:
        print(i, j)
        print(k, l)
        exit()

print(-1)