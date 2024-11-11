# https://codeforces.com/problemset/problem/1156/C

n, z = map(int, input().split())
numbers = sorted(list(map(int, input().split())))

matches, a, b = 0, 0, n // 2

while a <= n // 2 and b < n:
    if numbers[a] + z <= numbers[b]:
        matches += 1
        a += 1
    b += 1

print(matches)

