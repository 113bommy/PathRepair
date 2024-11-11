from collections import defaultdict

def count(k, A):
    M = {A[i]: (i + 1) for i in range(len(A))}
    shifted = {(i + 1): ((i + k) % len(A) + 1) for i in range(len(A))}

    r = 0
    for a in range(1, len(A) + 1):
        while M[a] != shifted[a]:
            sa = shifted[a]
                
            v = ((len(A) + M[a] - 1 - k) % len(A) + 1)

            shifted[a] = M[a]
            shifted[v] = sa
                
            a = v

            r += 1
    return r


T = int(input())
for _ in range(T):
    n, m = map(int, input().split(' '))
    A = [int(e) for e in input().split(' ')]

    M = {A[i]: (i + 1) for i in range(len(A))}

    K = defaultdict(int)
    for a in range(1, n + 1):
        if M[a] >= a:
            K[M[a] - a] += 1
        else:
            K[((M[a] + n) - a) % n] += 1

    R = []
    for k, v in sorted(K.items()):
        if (n - v) <= 2*m and count(k, A) <= m:
            R.append(k)

    print(" ".join(str(e) for e in [len(R)] + R))
