N = int(input())
M = N
result = []
i = 2
while i * i <= N:
    while N % i == 0:
        N /= i
        result.append(i)
    i += 1
if N > 1:
    result.append(N)
print(str(M) + ": " + " ".join(map(str, result)))
