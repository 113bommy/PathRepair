S = list(input())
k = int(input())

for i, s in enumerate(S):
    if ord('z') - ord(s) + 1 <= k:
        S[i] = 'a'
        k -= (ord('z') - ord(s) + 1)

S[-1] = chr((ord(S[-1]) + (k % 26)) % ord('a') % 26 + ord('a'))

print(str().join(S))