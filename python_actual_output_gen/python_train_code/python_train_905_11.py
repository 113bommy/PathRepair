N = int(input())
A = [int(input())-1 for _ in range(N)]
i = 0
for n in range(1, N+1):
    i = A[i]
    if i == 2:
        print(n)
        break
else:
    print(-1)