import string

s = input()
k = int(input())
w = [int(x) for x in input().split(' ')]
alpha = {k: v for (k, v) in zip(list(string.ascii_lowercase), w)}

c = 0
W = max(w)

for i in range(len(s)):
    c += alpha[s[i]] * (i + 1)

for i in range(len(s) + 1, len(s) + 1 + k):
    c += W * (i)


print(c)