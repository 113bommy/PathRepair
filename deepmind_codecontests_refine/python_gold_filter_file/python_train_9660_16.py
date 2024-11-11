S = input()
n = len(S) + 1
num = [0] * n
for i in range(n-1):
    if S[i] == '<':
        num[i + 1] = max(num[i] + 1, num[i + 1])
for i in range(n - 2, -1, -1):
    if S[i] == '>':
        num[i] = max(num[i + 1] + 1, num[i])
print(sum(num))