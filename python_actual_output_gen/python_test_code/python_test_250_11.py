N = int(input())
H = list(map(int, input().split()))

Hs = sorted(H)

for i in range(N):
    if H[i] - Hs[i] <= -2:
        print("No")
        break
else:
    print("Yes")