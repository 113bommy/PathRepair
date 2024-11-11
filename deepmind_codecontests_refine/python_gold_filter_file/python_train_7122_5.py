n, k = map(int, input().split())
owed = [0 for _ in range(n)]
owes = [0 for _ in range(n)]

for i in range(k):
    a, b, c = map(int, input().split())
    owed[b-1] += c
    owes[a-1] += c

sum = 0
for i in range(n):
    if (owes[i] > owed[i]):
        sum += owes[i] - owed[i]

print(sum)
