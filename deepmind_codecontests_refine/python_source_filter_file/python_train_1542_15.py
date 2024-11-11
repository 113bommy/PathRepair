N = int(input())
A = [int(i) for i in input().split()]
A.insert(0, 0)

ans = []
for i in reversed(range(1, N + 1)):
    if sum(A[i::i]) % 2 != A[i]:
        A[i] = ~A[i]
    if A[i] == 1:
        ans.append(i)

print(len(ans))
print(*ans)
