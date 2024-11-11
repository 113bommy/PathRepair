n, c = map(int, input().split())
t = list(map(int, input().split()))

nwords = 1
for i in range(1, n):
    if t[i] - t[i - 1] > c:
        nwords = 0
    else:
        nwords += 1
print(nwords)
