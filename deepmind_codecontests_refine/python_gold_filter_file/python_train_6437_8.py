S = input()

n = len(S)
a = n
for i in range(n-1):
    if S[i] != S[i+1]:
        a = min(a, max(i+1, n-i-1))

print(a)
