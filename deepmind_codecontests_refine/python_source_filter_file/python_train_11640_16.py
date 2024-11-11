N = int(input())
H = list(map(int, input().split()))
for i in range(1, N):
    M = max(M, H[i - 1])
    if H[i] < M - 1:
        print("No")
        exit()
print("Yes")
