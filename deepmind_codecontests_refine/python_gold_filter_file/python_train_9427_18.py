[n, k] = [int(item) for item in input().split(' ')]
c = [0] * 1000

for _ in range(n):
    c[len(input())] += 1

m = len(input())
s = 0
for i in range(m):
    s += c[i]

a = s
s += c[m]

best_penalty = a // k * 5 + a + 1
worst_penalty = (s - 1) // k * 5 + s

print(best_penalty, worst_penalty)
