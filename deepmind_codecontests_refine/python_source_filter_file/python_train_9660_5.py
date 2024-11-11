S = input()
N = len(S)
l = [0] * (N + 1)

for i in range(N):
    if S[i] == '<':
        l[i + 1] = max(l[i + 1], l[i] + 1)
for i in range(1, N)[::-1]:
    if S[i] == '>':
        l[i] = max(l[i], l[i + 1] + 1)

print(sum(l))
# print(l)
