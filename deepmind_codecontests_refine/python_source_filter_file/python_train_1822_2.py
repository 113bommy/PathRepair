n = int(input())
unseen = set(range(1, 10 ** 5 + 1))
seen = set()

a = [int(x) for x in input().split()]

for x in a:
    unseen.discard(x)

for i in range(len(a)):
    if a[i] in seen or a[i] < 1 or a[i] > n:
        a[i] = unseen.pop()

    seen.add(a[i])

print(*a)
