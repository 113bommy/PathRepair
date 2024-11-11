N, A = int(input()), list(map(int, input().split()))
s1, s2 = sum(A[1::2]), sum(A[2::2])
k = s1 == s2

for i in range(N - 1):
    if i % 2:
        s2 += A[i] - A[i + 1]
    else:
        s1 += A[i] - A[i + 1]
    k += s1 == s2

print(k)