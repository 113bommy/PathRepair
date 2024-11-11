S = input()
K = int(input())

A = []
for s in S:
    t = ord('z') - ord(s) + 1
    if t <= K:
        K -= t
        A.append('a')
    else:
        A.append(s)

A[-1] = chr((ord(A[-1]) + K - ord('a')) % 26 + ord('a'))
print("".join(A))